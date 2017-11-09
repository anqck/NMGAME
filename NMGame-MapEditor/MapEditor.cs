using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static NMGame_MapEditor.GameObject;

namespace NMGame_MapEditor
{
    public partial class MapEditor : Form
    {
        private Point mMousePosition;

        private List<GameObject> mListObject;
        public MapEditor()
        {
            InitializeComponent();
            mListObject = new List<GameObject>();

            foreach (EObjectID foo in EObjectID.GetValues(typeof(EObjectID)))
                cbObjType.Items.Add(foo.ToString());

            cbObjType.SelectedIndex = 0;
        }

        private void MapEditor_Load(object sender, EventArgs e)
        {
            this.mWorldSpace.MImage = new Bitmap(NMGame_MapEditor.Properties.Resources.MapLevel1);

            grpObjectInfo.Enabled = false;
            btnDelete.Enabled = false;
            btnEdit.Enabled = false;
            btnSave.Enabled = false;
        }

        private void mWorldSpace_MouseMove(object sender, MouseEventArgs e)
        {
            this.mMousePosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);

            this.toolStripStatusLabel1.Text = "Mouse Position: [" + this.mMousePosition.X + ", " + this.mMousePosition.Y + "] , World Position : [" + this.mMousePosition.X + ", " + (9542  - this.mMousePosition.Y) + "] ";

            if(e.Button == MouseButtons.Left && grpObjectInfo.Enabled == true)
            {
                this.mWorldSpace.DrawRectangle(mouseDownPosition.X, mouseDownPosition.Y, mMousePosition.X, mMousePosition.Y);
                this.mWorldSpace.Invalidate();
                this.txtLeft.Text = this.mWorldSpace.Rect.Left.ToString();
                this.txtTop.Text = this.mWorldSpace.Rect.Top.ToString();
                this.txtRight.Text = (this.mWorldSpace.Rect.Left + this.mWorldSpace.Rect.Width).ToString();
                this.txtBottom.Text = (this.mWorldSpace.Rect.Top + this.mWorldSpace.Rect.Height).ToString();
            }
        }


        Point mouseDownPosition, mouseUpPosition;
        private void mWorldSpace_MouseDown(object sender, MouseEventArgs e)
        {
            mouseDownPosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);

            
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            mListObject.Add(new GameObject(int.Parse(txtLeft.Text), int.Parse(txtTop.Text), int.Parse(txtRight.Text),int.Parse(txtBottom.Text), (EObjectID) cbObjType.SelectedIndex, int.Parse(txtObjectIdx.Text)));


            //Khởi gán lại textBox
            txtObjectIdx.Text = "";
            grpObjectInfo.Enabled = false;

            //Xóa hcn
            this.mWorldSpace.ClearRectangle();
            this.mWorldSpace.Invalidate();

            //Cập nhật danh sách Item
            ListViewUpdate();

            //
            btnSave.Enabled = false;
            btnDelete.Enabled = false;
        }

        private void ListViewUpdate()
        {
            //Xóa list cũ
            listView1.Items.Clear();

           foreach (GameObject obj in mListObject)
            {        
                //
                listView1.Items.Add(obj.MKey.ToString());
                listView1.Items[listView1.Items.Count - 1].SubItems.Add("["+ obj.MLeft.ToString() + "," + obj.MTop.ToString() + "," + obj.MRight.ToString() + "," + obj.MBottom.ToString() + "]");
                listView1.Items[listView1.Items.Count - 1].SubItems.Add(obj.MObjID.ToString());
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            txtObjectIdx.Text = mListObject.Count().ToString();

            grpObjectInfo.Enabled = true;
            btnDelete.Enabled = true;
            btnSave.Enabled = true;
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnBuildQuadTree_Click(object sender, EventArgs e)
        {

        }

        private void mWorldSpace_MouseUp(object sender, MouseEventArgs e)
        {
            mouseUpPosition = new Point(e.X - this.mWorldSpace.AutoScrollPosition.X, e.Y - this.mWorldSpace.AutoScrollPosition.Y);

            if (grpObjectInfo.Enabled == true)
            {
                this.mWorldSpace.DrawRectangle(mouseDownPosition.X, mouseDownPosition.Y, mouseUpPosition.X, mouseUpPosition.Y);
                this.mWorldSpace.Invalidate();
                this.txtLeft.Text = this.mWorldSpace.Rect.Left.ToString();
                this.txtTop.Text = this.mWorldSpace.Rect.Top.ToString();
                this.txtRight.Text = (this.mWorldSpace.Rect.Left+ this.mWorldSpace.Rect.Width).ToString();
                this.txtBottom.Text = (this.mWorldSpace.Rect.Top+ this.mWorldSpace.Rect.Height).ToString();
            }
           
        }
    }
}
