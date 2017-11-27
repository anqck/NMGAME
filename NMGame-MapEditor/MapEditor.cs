using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static NMGame_MapEditor.GameObject;

namespace NMGame_MapEditor
{
    enum CursorState
    {
        DoNothing,
        DrawRectangle,
        PlaceObject,
        DrawMoveRect
    }

    enum State
    {
        DoNothing,
        NewObject,
        EditObject
    }

    public partial class MapEditor : Form
    {
        private int WORLD_X;
        private int WORLD_Y;
        private OpenFileDialog open;
        private SaveFileDialog save;
        //zoom
        int zoom = 0;
        Image imageOriginal;


        private Point mMousePosition;
      

        private List<GameObject> mListObject;

        private QNode mQuadTreeRoot;

        private CursorState cursorState;
        private State currentState;

        List<GameObject> needToVisualize;

        public MapEditor()
        {
            InitializeComponent();
            mListObject = new List<GameObject>();

            foreach (EObjectID foo in EObjectID.GetValues(typeof(EObjectID)))
                cbObjType.Items.Add(foo.ToString());

            cursorState = CursorState.DoNothing;
            cursorState = CursorState.DoNothing;
            //cbObjType.SelectedIndex = 0;
            btnDrawRectangle.Visible = false;
            btnPlaceObject.Visible = false;
            btnDrawMoveRect.Visible = false;
        }

        private void MapEditor_Load(object sender, EventArgs e)
        {
            this.mWorldSpace.MImage = new Bitmap(NMGame_MapEditor.Properties.Resources.MapLevel1);
            imageOriginal = mWorldSpace.MImage;

            grpObjectInfo.Enabled = false;
            btnDelete.Enabled = false;
            btnEdit.Enabled = false;
            btnSave.Enabled = false;

            this.grpMove.Visible = false;
            chkStair.Visible = false;
            txtStairLayer.Visible = false;
            txtStairLayerCh.Visible = false;

            needToVisualize = new List<GameObject>();
            lblzoom.Text = zoom + " %";
        }


        #region WorldSpace

        private void mWorldSpace_MouseMove(object sender, MouseEventArgs e)
        {
            this.mMousePosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);
            this.toolStripStatusLabel1.Text = "Mouse Position: [" + this.mMousePosition.X + ", " + this.mMousePosition.Y + "] , World Position : [" + this.mMousePosition.X + ", " + (10494 - this.mMousePosition.Y) + "] ";

            if (e.Button != MouseButtons.Left)
                return;

                switch (cursorState)
            {
                case CursorState.DrawRectangle:
                    this.mWorldSpace.DrawRectangle(mouseDownPosition.X, mouseDownPosition.Y, mMousePosition.X, mMousePosition.Y);
                    this.mWorldSpace.Invalidate();
                    this.txtLeft.Text = this.mWorldSpace.Rect.Left.ToString();
                    this.txtTop.Text = this.mWorldSpace.Rect.Top.ToString();
                    this.txtRight.Text = (this.mWorldSpace.Rect.Left + this.mWorldSpace.Rect.Width).ToString();
                    this.txtBottom.Text = (this.mWorldSpace.Rect.Top + this.mWorldSpace.Rect.Height).ToString();

                    break;
                case CursorState.DrawMoveRect:
                    this.mWorldSpace.DrawMoveRectangle(mouseDownPosition.X, mouseDownPosition.Y, mMousePosition.X, mMousePosition.Y);
                    this.mWorldSpace.Invalidate();
                    this.txtmoveLeft.Text = this.mWorldSpace.Moverect.Left.ToString();
                    this.txtmoveTop.Text = this.mWorldSpace.Moverect.Top.ToString();
                    this.txtmoveRight.Text = (this.mWorldSpace.Moverect.Left + this.mWorldSpace.Moverect.Width).ToString();
                    this.txtmoveBottom.Text = (this.mWorldSpace.Moverect.Top + this.mWorldSpace.Moverect.Height).ToString();

                    break;
                case CursorState.PlaceObject:              

                    
                    break;
                default:
                    break;
            }

               

                
        }

       

        Point mouseDownPosition, mouseUpPosition;
        private void mWorldSpace_MouseDown(object sender, MouseEventArgs e)
        {
            mouseDownPosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);

            flagBiding = false;

            switch (cursorState)
            {
                case CursorState.DrawRectangle:
                    

                    break;
                case CursorState.PlaceObject:
                    Bitmap img = GameObject.GetObjectImg((EObjectID)this.cbObjType.SelectedIndex);
                    this.mWorldSpace.SetImageObject(img, mouseDownPosition.X - img.Size.Width / 2, mouseDownPosition.Y - img.Size.Height );

                    txtPosX.Text =  (mouseDownPosition.X ).ToString();
                    txtPosY.Text = (mouseDownPosition.Y ).ToString();

                    if (!GameObject.isObjectNeedDrawBoundingRect((EObjectID)this.cbObjType.SelectedIndex))
                    {
                        txtLeft.Text = (mouseDownPosition.X - img.Size.Width/2).ToString();
                        txtRight.Text = (mouseDownPosition.X + img.Size.Width / 2).ToString();
                        txtTop.Text = (mouseDownPosition.Y - img.Size.Height).ToString();
                        txtBottom.Text = (mouseDownPosition.Y ).ToString();
                    }
                    flagPic = true;
                        break;
                default:
                    break;
            }            
        }

        private void mWorldSpace_MouseUp(object sender, MouseEventArgs e)
        {
            mouseUpPosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);

            switch (cursorState)
            {
                case CursorState.DrawRectangle:
                    if (grpObjectInfo.Enabled == true)
                    {
                        this.mWorldSpace.DrawRectangle(mouseDownPosition.X, mouseDownPosition.Y, mouseUpPosition.X, mouseUpPosition.Y);
                        this.mWorldSpace.Invalidate();
                        this.txtLeft.Text = this.mWorldSpace.Rect.Left.ToString();
                        this.txtTop.Text = this.mWorldSpace.Rect.Top.ToString();
                        this.txtRight.Text = (this.mWorldSpace.Rect.Left + this.mWorldSpace.Rect.Width).ToString();
                        this.txtBottom.Text = (this.mWorldSpace.Rect.Top + this.mWorldSpace.Rect.Height).ToString();

                    }
                    flagBiding = true;

                    break;

                case CursorState.PlaceObject:
                    break;
                default:
                    break;
            }
        }

        #endregion

        #region Button
        private void btnSave_Click(object sender, EventArgs e)
        {
            if(CheckCondition())
            {
                return;
            }

            switch (currentState)
            {
                case State.NewObject:
                    if (GameObject.isObjectNeedPosition((EObjectID)this.cbObjType.SelectedIndex))
                    {
                        //if (GameObject.isObjectNeedMoveRect((EObjectID)this.cbObjType.SelectedIndex))
                        //{
                        //    mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text), int.Parse(txtBottom.Text),new MyRECT(int.Parse(txtmoveLeft.Text), int.Parse(txtmoveTop.Text), int.Parse(txtmoveBottom.Text), int.Parse(txtmoveRight.Text)), (EObjectID)cbObjType.SelectedIndex, int.Parse(txtPosX.Text), int.Parse(txtPosY.Text)));

                        //}
                        //else
                        {
                            mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text), int.Parse(txtBottom.Text), (EObjectID)cbObjType.SelectedIndex, int.Parse(txtPosX.Text), int.Parse(txtPosY.Text)));
                        }
                    }
                    else
                    {
                        if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIR)
                        {
                            mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text), int.Parse(txtBottom.Text), (EObjectID)cbObjType.SelectedIndex,0,0,int.Parse(txtStairLayer.Text)));
                        }
                        else if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIRFLAGCHANGE)
                        {
                            mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text), int.Parse(txtBottom.Text), (EObjectID)cbObjType.SelectedIndex, 0, 0, int.Parse(txtStairLayerCh.Text), int.Parse(txtStairLayer.Text)));
                        }
                        else
                            mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text), int.Parse(txtBottom.Text), (EObjectID)cbObjType.SelectedIndex));
                    }
                        
                    break;
                case State.EditObject:
                    btnEdit.Enabled = false;
                    btnNew.Enabled = true;

                    if (listView1.SelectedIndices.Count != 0)
                    {
                       
                            mListObject[listView1.SelectedIndices[0]].MPositionY = int.Parse(txtPosY.Text);
                            mListObject[listView1.SelectedIndices[0]].MPositionX = int.Parse(txtPosX.Text);
                            mListObject[listView1.SelectedIndices[0]].MBottom = int.Parse(txtBottom.Text);
                            mListObject[listView1.SelectedIndices[0]].MLeft = int.Parse(txtLeft.Text);
                            mListObject[listView1.SelectedIndices[0]].MRight = int.Parse(txtRight.Text);
                            mListObject[listView1.SelectedIndices[0]].MTop = int.Parse(txtTop.Text);

                        if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIR)
                        {

                             mListObject[listView1.SelectedIndices[0]].MStairLayer = int.Parse(txtStairLayer.Text) ;
                        }
                        else if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIRFLAGCHANGE)
                        {

                            mListObject[listView1.SelectedIndices[0]].MStairLayerChangeFr = int.Parse(txtStairLayerCh.Text);
                            mListObject[listView1.SelectedIndices[0]].MStairLayerChangeTo = int.Parse(txtStairLayer.Text);
                        }
                    }
                    break;
                default:
                    break;
            }

            cursorState = CursorState.DoNothing;
            currentState = State.DoNothing;

            //Khởi gán lại textBox
            grpObjectInfo.Enabled = false;

            //Xóa hcn
            this.mWorldSpace.ClearRectangle();
            this.mWorldSpace.ClearObjectImage();
            this.mWorldSpace.Invalidate();

            //Cập nhật danh sách Item
            ListViewUpdate();

            //
            btnSave.Enabled = false;
            btnDelete.Enabled = false;
        }

        private bool CheckCondition()
        {
            if(GameObject.isObjectNeedPosition((EObjectID)this.cbObjType.SelectedIndex))
            {
                if (txtPosX.Text == "" || txtPosY.Text == "")
                {
                    MessageBox.Show("Chưa nhập vào vị trí", "Thông Báo", MessageBoxButtons.OK, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
                    return true;
                }
                    
            }

            if (txtLeft.Text == "" || txtRight.Text == "" || txtBottom.Text == "" || txtTop.Text == "")
            {
                MessageBox.Show("Chưa nhập vào bounding box", "Thông Báo", MessageBoxButtons.OK, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
                return true;
            }

            return false;
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            currentState = State.NewObject;

            cbObjType.SelectedIndex = 0;

            StateUpdate(currentState);
                 
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            currentState = State.EditObject;
            
            StateUpdate(currentState);


            
        }

        private void StateUpdate(State currentState)
        {
            this.mWorldSpace.ClearRectangle();
            this.mWorldSpace.ClearObjectImage();
            this.mWorldSpace.Invalidate();

            if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIR)
            {
                txtStairLayer.Visible = true;
                //chkStair.Visible = true;
            }
            else if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIRFLAGCHANGE)
            {
                txtStairLayer.Visible = true;
                txtStairLayerCh.Visible = true;
            }

            switch (currentState)
            {
                case State.NewObject:
                    currentState = State.NewObject;
                    cursorState = CursorState.DrawRectangle;

                    //cbObjType.SelectedIndex = 0;

                    txtBottom.Text = "";
                    txtLeft.Text = "";
                    txtRight.Text = "";
                    txtTop.Text = "";

                    grpObjectInfo.Enabled = true;
                    btnSave.Enabled = true;
                    btnDelete.Enabled = false;

                    break;
                case State.EditObject:
                    grpObjectInfo.Enabled = true;
                    if(GameObject.isObjectNeedPosition((EObjectID) cbObjType.SelectedIndex))
                        cursorState = CursorState.PlaceObject;
                    else
                         cursorState = CursorState.DrawRectangle;
                    btnEdit.Enabled = false;
                    btnSave.Enabled = true;
                    btnDelete.Enabled = false;
                    btnNew.Enabled = false;
                    flagBiding = true;
                    if (mListObject[listView1.SelectedIndices[0]].MObjID == EObjectID.GROUND)
                    { grpPosition.Enabled = false; }

                    break;
                case State.DoNothing:
                    btnEdit.Enabled = false;
                    btnDelete.Enabled = false;
                    btnNew.Enabled = true;
                    btnSave.Enabled = false;
                    grpObjectInfo.Enabled = false;
                    cursorState = CursorState.DoNothing;
                    break;                   
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int stt = -1;
            for (int i = 0; i < listView1.Items.Count; i++)
            {
                if (listView1.Items[i].Selected)
                {
                    listView1.Items[i].Remove();
                    stt = i;
                    i--;
                }
            }
            mListObject.RemoveAt(stt);
            //Xóa hcn
            this.mWorldSpace.ClearRectangle();

            foreach (int idx in listView1.CheckedIndices)
            {
                needToVisualize.Add(mListObject[idx]);
            };

            mWorldSpace.VisualizeListObject(needToVisualize);
            needToVisualize.Clear();
            ListViewUpdate();

            btnDelete.Enabled = false;
            btnEdit.Enabled = false;

            foreach (int idx in listView1.CheckedIndices)
            {
                needToVisualize.Add(mListObject[idx]);
            };

            mWorldSpace.VisualizeListObject(needToVisualize);
            needToVisualize.Clear();


        }     

        private void btnBuildQuadTree_Click(object sender, EventArgs e)
        {

            WORLD_X = WORLD_Y = Math.Max(this.mWorldSpace.MImage.Size.Width, this.mWorldSpace.MImage.Size.Height);

            mQuadTreeRoot = new QNode(1, 1, WORLD_Y, 0, WORLD_X, 0);
            mQuadTreeRoot.Init();



            //Gasn Key và đưa các Object vào node gốc
            for (int i = 0; i < this.mListObject.Count; i++)
            {
                this.mListObject[i].MKey = i;
                this.mQuadTreeRoot.MListObject.Add(this.mListObject[i]);
            }
                         

            //Build tree
            this.mQuadTreeRoot.BuildTree();

            //Save QuadTree
            this.SaveQuadTree();

        }

        #endregion

        #region ListView
        private void ListViewUpdate()
        {
            //Xóa list cũ
            
            listView1.Items.Clear();
            
            foreach (GameObject obj in mListObject)
            {
                //
                listView1.Items.Add(listView1.Items.Count.ToString());

                if (GameObject.isObjectNeedPosition(obj.MObjID))
                    listView1.Items[listView1.Items.Count - 1].SubItems.Add("[" + obj.MPositionX + "," + obj.MPositionY + "]");
                else
                    listView1.Items[listView1.Items.Count - 1].SubItems.Add("[_,_]");
                listView1.Items[listView1.Items.Count - 1].SubItems.Add("[" + obj.MLeft.ToString() + "," + obj.MTop.ToString() + "," + obj.MRight.ToString() + "," + obj.MBottom.ToString() + "]");
                listView1.Items[listView1.Items.Count - 1].SubItems.Add(obj.MObjID.ToString());

                listView1.Items[listView1.Items.Count - 1].Checked = true;
            }
        }
        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            currentState = State.DoNothing;

            StateUpdate(currentState);

            ViewSelectedListViewItem();

                 


        }

        private void ViewSelectedListViewItem()
        {
            if (listView1.SelectedIndices.Count != 0)
            {
                // MessageBox.Show(listView1.SelectedIndices[0].ToString());
                cbObjType.Text = mListObject[listView1.SelectedIndices[0]].MObjID.ToString();
                txtLeft.Text = mListObject[listView1.SelectedIndices[0]].MLeft.ToString();
                txtTop.Text = mListObject[listView1.SelectedIndices[0]].MTop.ToString();
                txtRight.Text = mListObject[listView1.SelectedIndices[0]].MRight.ToString();
                txtBottom.Text = mListObject[listView1.SelectedIndices[0]].MBottom.ToString();
                txtPosX.Text= mListObject[listView1.SelectedIndices[0]].MPositionX.ToString();
                txtPosY.Text = mListObject[listView1.SelectedIndices[0]].MPositionY.ToString();
                txtmoveLeft.Text = mListObject[listView1.SelectedIndices[0]].getMoveRect().Left.ToString();
                txtmoveTop.Text = mListObject[listView1.SelectedIndices[0]].getMoveRect().Top.ToString();
                txtmoveRight.Text = mListObject[listView1.SelectedIndices[0]].getMoveRect().Right.ToString();
                txtmoveBottom.Text = mListObject[listView1.SelectedIndices[0]].getMoveRect().Bottom.ToString();

                if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIR)
                {
                    //chkStair.Visible = true;
                    txtStairLayer.Visible = true;
                    //chkStair.Checked =  mListObject[listView1.SelectedIndices[0]].MStairFlag;
                    txtStairLayer.Text = mListObject[listView1.SelectedIndices[0]].MStairLayer.ToString();
                }
                else if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIRFLAGCHANGE)
                {

                    txtStairLayer.Visible = true;
                    txtStairLayerCh.Visible = true;

                    txtStairLayer.Text = mListObject[listView1.SelectedIndices[0]].MStairLayerChangeTo.ToString();
                    txtStairLayerCh.Text = mListObject[listView1.SelectedIndices[0]].MStairLayerChangeFr.ToString();
                }


                flagBiding = false;
                Biding();

      
                mWorldSpace.VisualizeObject(mListObject[listView1.SelectedIndices[0]]);

                btnEdit.Enabled = true;
                btnDelete.Enabled = true;
            }
        }

        private void listView1_ItemChecked(object sender, ItemCheckedEventArgs e)
        {

            foreach (int idx in listView1.CheckedIndices)
            {
                needToVisualize.Add(mListObject[idx]);
            };

            mWorldSpace.VisualizeListObject(needToVisualize);
            needToVisualize.Clear();

        }
        #endregion

        #region GroupInformation
        bool flagBiding = false;
        private void Biding()
        {
            if (!flagBiding) return;

            try
            {
                if (this.txtLeft.Text != "" && this.txtTop.Text != "" && this.txtRight.Text != "" && this.txtBottom.Text != "")
                {
                    int L = int.Parse(this.txtLeft.Text);
                    int T = int.Parse(this.txtTop.Text);
                    int R = int.Parse(this.txtRight.Text);
                    int B = int.Parse(this.txtBottom.Text);
                    this.mWorldSpace.DrawRectangle(L, T, R, B);
                    this.mWorldSpace.Invalidate();
                }
            }
            catch
            {

            }
            
        }
        
        private void txt_TextChanged(object sender, EventArgs e)
        {
           Biding();
        }

        private void cbObjType_SelectedIndexChange(object sender, EventArgs e)
        {
            this.mWorldSpace.ClearObjectImage();
            this.mWorldSpace.ClearRectangle();

            txtLeft.Text = "";
            txtRight.Text = "";
            txtTop.Text = "";
            txtBottom.Text = "";
            txtPosX.Text = "";
            txtPosY.Text = "";

            txtmoveLeft.Text = "";
            txtmoveRight.Text = "";
            txtmoveTop.Text = "";
            txtmoveBottom.Text = "";

            txtStairLayer.Text = "0";
            txtStairLayerCh.Text = "0";


            btnDrawRectangle.Visible = false;
            btnPlaceObject.Visible = false;
            btnDrawMoveRect.Visible = false;
            chkStair.Visible = false;
            txtStairLayer.Visible = false;
            txtStairLayerCh.Visible = false;
            switch (currentState)
            {
                case State.NewObject:
                case State.EditObject:
                    if((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIR)
                    {
                        txtStairLayer.Visible = true;
                    }
                    else if ((EObjectID)this.cbObjType.SelectedIndex == EObjectID.STAIRFLAGCHANGE)
                    {
                        txtStairLayerCh.Visible = true;
                        txtStairLayer.Visible = true;
                    }


                    if (GameObject.isObjectNeedPosition((EObjectID)this.cbObjType.SelectedIndex))
                    {
                        if (GameObject.isObjectNeedDrawBoundingRect((EObjectID)this.cbObjType.SelectedIndex))
                        {
                            grpPosition.Enabled = true;
                            grpBounded.Enabled = true;

                            btnDrawRectangle.Visible = true;
                            btnPlaceObject.Visible = true;

                            cursorState = CursorState.DrawRectangle;

                            //if (GameObject.isObjectNeedMoveRect((EObjectID)this.cbObjType.SelectedIndex))
                            //{

                            //    grpMove.Enabled = true;
                            //    btnDrawMoveRect.Visible = true;

                            //}
                        }
                        else
                        {
                            cursorState = CursorState.PlaceObject;

                            grpPosition.Enabled = true;
                            grpBounded.Enabled = false;
                            grpMove.Enabled = false;
                        }
                        
                    }
                    else
                    {
                        cursorState = CursorState.DrawRectangle;
                        grpPosition.Enabled = false;
                        grpBounded.Enabled = true;
                        grpMove.Enabled = false;

                    }
                    

                    break;
                case State.DoNothing:
                    break;
            }
           
        }

        private void btnPlaceObject_Click(object sender, EventArgs e)
        {
            cursorState = CursorState.PlaceObject;
        }

        private void btnDrawRectangle_Click(object sender, EventArgs e)
        {
            cursorState = CursorState.DrawRectangle;
        }

       

        private void btnImport_Click(object sender, EventArgs e)
        {
            mListObject.Clear();

            //dosomething
            open = new OpenFileDialog();
           // open.Filter = "|*.txt";
           open.Filter = "txt files (*.txt)|*.txt";
           // open.FilterIndex = 2;
            if (open.ShowDialog() == DialogResult.OK)
            {
                StreamReader read = new StreamReader(open.FileName);
                String data = read.ReadToEnd();
                string[] nodes = data.Split('|');

                for (int i = 0; i < nodes.Length; i++)
                {
                    string[] temp = nodes[i].Split('/');
                    mListObject.Add(new GameObject(int.Parse(temp[0]), int.Parse(temp[1]), int.Parse(temp[2]), int.Parse(temp[3]), (EObjectID)Enum.ToObject(typeof(EObjectID), int.Parse(temp[4])),int.Parse(temp[5]),int.Parse(temp[6]), int.Parse(temp[7]), int.Parse(temp[8])));
                    // mListObject.Add(new GameObject(900, 500, 700, 1110, (EObjectID.GROUND)));


                }

                read.Close();

            }
            ListViewUpdate();

        }

        private void btnExport_Click(object sender, EventArgs e)
        {
            //do domething
            save = new SaveFileDialog();
            save.Filter = "(*.txt)|*.txt";
            save.RestoreDirectory = true; //cho phep ghi de
            if (save.ShowDialog() == DialogResult.OK)
            {
                StreamWriter write = new StreamWriter(save.FileName);
                //doing something

                GameObject last = mListObject.Last();
                foreach (GameObject temp in mListObject)
                {
                    if (temp.Equals(last))
                    {
                        write.Write(temp.MLeft + "/" + temp.MTop + "/" + temp.MRight + "/" + temp.MBottom + "/" + (int)temp.MObjID + "/" + temp.MPositionX + "/"+ temp.MPositionY + "/" + temp.MStairLayer +"/" + temp.MStairLayerChangeTo);
                    }
                    else
                    {
                        write.Write(temp.MLeft + "/" + temp.MTop + "/" + temp.MRight + "/" + temp.MBottom + "/" + (int)temp.MObjID + "/" + temp.MPositionX + "/" + temp.MPositionY + "/" + temp.MStairLayer +  "/" + temp.MStairLayerChangeTo + "|");
                    }
                    // write.Write(temp.MTop + "/"+temp.MLeft + "/" + temp.MRight + "/" + temp.MBottom +"/"+ (int)temp.MObjID + "|" );

                }

                write.Close();
            }


        }
        bool flagPic = false;
        private void txtPosX_TextChanged(object sender, EventArgs e)
        {
            if (!flagPic) return;

            if (txtPosX.Text != "" && txtPosY.Text != "")
            {
                Bitmap img = GameObject.GetObjectImg((EObjectID)this.cbObjType.SelectedIndex);
                this.mWorldSpace.SetImageObject(img, int.Parse(txtPosX.Text) - img.Size.Width / 2, int.Parse(txtPosY.Text) - img.Size.Height);

                if (!GameObject.isObjectNeedDrawBoundingRect((EObjectID)this.cbObjType.SelectedIndex))
                {
                    txtLeft.Text = (int.Parse(txtPosX.Text) - img.Size.Width / 2).ToString();
                    txtRight.Text = (int.Parse(txtPosX.Text) + img.Size.Width / 2).ToString();
                    txtTop.Text = (int.Parse(txtPosY.Text) - img.Size.Height).ToString();
                    txtBottom.Text = (int.Parse(txtPosY.Text)).ToString();
                }
            }
           // flagPic = false;
        }

        private void txtPosY_TextChanged(object sender, EventArgs e)
        {
            if (!flagPic) return;

            if (txtPosX.Text != "" && txtPosY.Text != "")
            {
                Bitmap img = GameObject.GetObjectImg((EObjectID)this.cbObjType.SelectedIndex);
                this.mWorldSpace.SetImageObject(img, int.Parse(txtPosX.Text) - img.Size.Width / 2, int.Parse(txtPosY.Text) - img.Size.Height);

                if (!GameObject.isObjectNeedDrawBoundingRect((EObjectID)this.cbObjType.SelectedIndex))
                {
                    txtLeft.Text = (int.Parse(txtPosX.Text) - img.Size.Width / 2).ToString();
                    txtRight.Text = (int.Parse(txtPosX.Text) + img.Size.Width / 2).ToString();
                    txtTop.Text = (int.Parse(txtPosY.Text) - img.Size.Height).ToString();
                    txtBottom.Text = (int.Parse(txtPosY.Text)).ToString();
                }
            }
        }

        private void mWorldSpace_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode== Keys.Z)
            {
                zoom++;
                lblzoom.Text = zoom + " &";
                

            }
            if (e.KeyCode == Keys.X)
            {
                zoom--;
                lblzoom.Text = zoom + " &";


            }

        }
      
        private void MapEditor_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Z)
            {
                zoom++;
                lblzoom.Text = zoom + " &";


            }
            if (e.KeyCode == Keys.X)
            {
                zoom--;
                lblzoom.Text = zoom + " &";


            }

        }
        private void MapEditor_MouseWheel(object sender, MouseEventArgs e)
        {
            if (e.Delta > 0) zoom++;
            else zoom--;
            lblzoom.Text = zoom + " %";
           // mWorldSpace.MImage = Zoomimg(imageOriginal, new Size(zoom, zoom));
           //MessageBox.Show("");
        }
        private Image Zoomimg(Image img, Size size)
        {
            // Bitmap bmp = new Bitmap(img, img.Width + (img.Width * size.Width / 100), img.Height + (img.Height * size.Height / 100));
            Bitmap bmp = new Bitmap(img, img.Width +size.Width*100 , img.Height+size.Height*100);
            Graphics g = Graphics.FromImage(bmp);
            g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
            return bmp;
        }

        private void mWorldSpace_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            cursorState = CursorState.DrawMoveRect;
        }


        #endregion

        #region QuadTree
        private void SaveQuadTree()
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text|*.txt";
            saveFileDialog.Title = "Save Quadtree";

            if (saveFileDialog.ShowDialog() != DialogResult.OK)
                return;

            string path = saveFileDialog.FileName;

            using (StreamWriter outputFile = new StreamWriter(path))
            {
                outputFile.WriteLine(this.mListObject.Count + " " + WORLD_X + " " + WORLD_Y);

                //Save các Object
                for (int i = 0; i < this.mListObject.Count; i++)
                {
                    if (mListObject[i].MObjID== EObjectID.STAIR)
                        outputFile.WriteLine(i + " " + (int)mListObject[i].MObjID + " " + mListObject[i].MPositionX + " " + (10494 - mListObject[i].MPositionY).ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MTop.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MLeft.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MRight.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MBottom.ToString() + " " + mListObject[i].MStairLayer.ToString());
                    else if (mListObject[i].MObjID == EObjectID.STAIRFLAGCHANGE)
                        outputFile.WriteLine(i + " " + (int)mListObject[i].MObjID + " " + mListObject[i].MPositionX + " " + (10494 - mListObject[i].MPositionY).ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MTop.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MLeft.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MRight.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MBottom.ToString() + " " + mListObject[i].MStairLayerChangeFr.ToString() + " " + mListObject[i].MStairLayerChangeTo.ToString());
                    else
                        outputFile.WriteLine(i + " " + (int)mListObject[i].MObjID + " " + mListObject[i].MPositionX + " " + (10494 - mListObject[i].MPositionY).ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MTop.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MLeft.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MRight.ToString() + " " + mListObject[i].getBoundingBoxInWorldAxis().MBottom.ToString());
                    
                }

                //Save các Node của QuadTree
                mQuadTreeRoot.SaveQuadTree(outputFile);


            }

        }
        #endregion


      
    }
}
