using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMGame_MapEditor
{
    class QNode
    {
        private const int MAX_LEVEL = 5;
        private const int MAX_OBJECT = 1;

        private int mLevel;
        private int mID;

        private int mLeft;
        private int mRight;
        private int mTop;
        private int mBottom;

        private List<GameObject> mListObject;
        private QNode[] mChilds;

        public int MLevel
        {
            get
            {
                return mLevel;
            }

            set
            {
                mLevel = value;
            }
        }

        public int MID
        {
            get
            {
                return mID;
            }

            set
            {
                mID = value;
            }
        }

        internal QNode[] MChilds
        {
            get
            {
                return mChilds;
            }

            set
            {
                mChilds = value;
            }
        }

        public QNode NodeLT
        {
            get { return (mChilds == null) ? null : mChilds[0]; }
            set { mChilds[0] = value; }
        }

        public QNode NodeRT
        {
            get { return (mChilds == null) ? null : mChilds[1]; }
            set { mChilds[1] = value; }
        }

        public QNode NodeLB
        {
            get { return (mChilds == null) ? null : mChilds[2]; }
            set { mChilds[2] = value; }
        }

        public QNode NodeRB
        {
            get { return (mChilds == null) ? null : mChilds[3]; }
            set { mChilds[3] = value; }
        }

        public List<GameObject> MListObject
        {
            get
            {
                return mListObject;
            }

            set
            {
                mListObject = value;
            }
        }

        public MyRECT getBoundingBox()
        {
            return new MyRECT(mLeft, mTop, mBottom, mRight);
        }

        public QNode(int id, int level, int top, int left, int right, int bottom)
        {
            this.mLevel = level;
            this.mID = id;
            this.mTop = top;
            this.mLeft = left;
            this.mRight = right;
            this.mBottom = bottom;

            this.mChilds = new QNode[4];
            this.MListObject = new List<GameObject>();

            for (int i = 0; i < mChilds.Count(); i++)
            {
                this.mChilds[i] = null;
            }
        }

        public void Init()
        {
            //Xóa danh sách các object của node
            this.MListObject.Clear();


            //Đệ quy node con
            for (int i = 0; i < mChilds.Length; i++)
            {
                if (mChilds[i] != null)
                {
                    mChilds[i].Init();
                    mChilds[i] = null;
                }
            }
        }

        private void Split()
        {
            this.NodeLT = new QNode(this.mID * 10, this.mLevel + 1, mTop, mLeft, (mRight - mLeft) / 2, (mTop - mBottom) / 2);
            this.NodeRT = new QNode(this.mID * 10 + 1, this.mLevel + 1, mTop, (mRight - mLeft) / 2, mRight, (mTop - mBottom) / 2);
            this.NodeLB = new QNode(this.mID * 10 + 2, this.mLevel + 1, (mTop - mBottom) / 2, mLeft, (mRight - mLeft) / 2, mBottom);
            this.NodeRB = new QNode(this.mID * 10 + 3, this.mLevel + 1, (mTop - mBottom) / 2, (mRight - mLeft) / 2, mRight, mBottom);
        }



        private int getObjectNodeID(GameObject obj)
        {

            //Lấy bounding box của obj
            MyRECT rectObject = obj.getBoundingBoxInWorldAxis();

            MyRECT rectLT = this.NodeLT.getBoundingBox();
            MyRECT rectRT = this.NodeRT.getBoundingBox();
            MyRECT rectLB = this.NodeLB.getBoundingBox();
            MyRECT rectRB = this.NodeRB.getBoundingBox();

            //Kiểm tra xem Object có nằm trọn trong node phần tư nào
            if (rectLT.Contains(rectObject))
                return 1;
            else if (rectRT.Contains(rectObject))
                return 2;
            else if (rectLB.Contains(rectObject))
                return 3;
            else if (rectRB.Contains(rectObject))
                return 4;
            else //Nếu Object nằm ở nhiều node
            {
                int id = 0;
                if (rectObject.Intersects(rectLT))
                    id = 1;

                if (rectObject.Intersects(rectRT))
                    id = id * 10 + 2;

                if (rectObject.Intersects(rectLB))
                    id = id * 10 + 3;

                if (rectObject.Intersects(rectRB))
                    id = id * 10 + 4;

                return id;
            }
        }

        public void BuildTree()
        {
            //Điều kiện dừng
            if (this.mLevel >= MAX_LEVEL || this.MListObject.Count <= MAX_OBJECT)
                return;

            //Nếu chia nhỏ node
            if (mChilds[0] == null)
                this.Split();

            //Đẩy các Object từ node cha xuống node con
            for (int i = 0; i < this.MListObject.Count; i++)
            {
                GameObject obj = this.MListObject[i];

                int index = this.getObjectNodeID(obj);

                switch (index)
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        {
                            this.mChilds[index - 1].MListObject.Add(obj);
                            break;
                        }
                    case 12:
                        {
                            mChilds[0].MListObject.Add(obj);
                            mChilds[1].MListObject.Add(obj);
                            break;
                        }
                    case 13:
                        {
                            mChilds[0].MListObject.Add(obj);
                            mChilds[2].MListObject.Add(obj);
                            break;
                        }
                    case 24:
                        {
                            mChilds[1].MListObject.Add(obj);
                            mChilds[3].MListObject.Add(obj);
                            break;
                        }
                    case 34:
                        {
                            mChilds[2].MListObject.Add(obj);
                            mChilds[3].MListObject.Add(obj);
                            break;
                        }
                    case 1234:
                        {
                            mChilds[0].MListObject.Add(obj);
                            mChilds[1].MListObject.Add(obj);
                            mChilds[2].MListObject.Add(obj);
                            mChilds[3].MListObject.Add(obj);
                            break;
                        }
                }
            }
            this.MListObject.Clear();

            //Gọi đệ quy xuống các node con
            for (int i = 0; i < mChilds.Count(); i++)
                mChilds[i].BuildTree();

        }

        internal void SaveQuadTree(StreamWriter outputFile)
        {
           
            if (mChilds[0] != null) //Không phải là lá thì lưu các thông tin và gọi đệ quy đến các node con
            {
                outputFile.WriteLine(this.mID + " " + this.mTop + " " + this.mLeft + " " + this.mRight + " " + this.mBottom + " " + this.mListObject.Count);
                this.mChilds[0].SaveQuadTree(outputFile);
                this.mChilds[1].SaveQuadTree(outputFile);
                this.mChilds[2].SaveQuadTree(outputFile);
                this.mChilds[3].SaveQuadTree(outputFile);
            }
            else //Nếu là lá thì lưu các thông tin về node VÀ các Object trong node đó
            {
                outputFile.Write(this.mID + " " + this.mTop + " " + this.mLeft + " " + this.mRight + " " + this.mBottom + " " + this.mListObject.Count);
                foreach (GameObject obj in this.mListObject)
                {
                    outputFile.Write(" " + obj.MKey);
                }
                outputFile.WriteLine();
            }
        }
    }
}
