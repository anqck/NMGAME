using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMGame_MapEditor
{
    class QNode
    {
        private const int           MAX_LEVEL = 5;
        private const int           MAX_OBJECT = 1;

        private int                 mLevel;
        private int                 mID;

        private int                 mLeft;
        private int                 mRight;
        private int                 mTop;
        private int                 mBottom;

        private List<GameObject>    mListObject;
        private QNode[]             mChilds;

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

        public QNode(int id, int level, int top, int left, int right, int bottom)
        {
            this.mLevel = level;
            this.mTop = top;
            this.mLeft = left;
            this.mRight = right;
            this.mBottom = bottom;

            this.mChilds = new QNode[4];
            this.mListObject = new List<GameObject>();

            for (int i = 0; i < mChilds.Count(); i++)
            {
                this.mChilds[i] = null;
            }
        }

        public void Init()
        {
            //Xóa danh sách các object của node
            this.mListObject.Clear();


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
            this.NodeRT = new QNode(this.mID * 10 + 1 , this.mLevel + 1, mTop, (mRight - mLeft) / 2, mRight, (mTop - mBottom) / 2);
            this.NodeLB = new QNode(this.mID * 10 + 2, this.mLevel + 1, (mTop - mBottom) / 2, mLeft, (mRight - mLeft) / 2, mBottom );
            this.NodeRB = new QNode(this.mID * 10 + 3, this.mLevel + 1, (mTop - mBottom) / 2, (mRight - mLeft) / 2, mRight, mBottom );
        }

        private int getObjectNodeID(GameObject obj)
        {
            return 0;
            ////in viewport
            //WorldRect rectObject = new WorldRect(obj.X, obj.Y, obj.Width, obj.Height);

            //int subWidth = Width / 2;
            //int subHeight = Height / 2;

            //int x = X;
            //int y = 9542 - Y;

            //WorldRect rectLT = this.NodeLT.Bound;
            //WorldRect rectRT = this.NodeRT.Bound;
            //WorldRect rectLB = this.NodeLB.Bound;
            //WorldRect rectRB = this.NodeRB.Bound;

            //if (rectLT.Contains(rectObject))
            //    return 1;
            //else if (rectRT.Contains(rectObject))
            //    return 2;
            //else if (rectLB.Contains(rectObject))
            //    return 3;
            //else if (rectRB.Contains(rectObject))
            //    return 4;
            //else
            //{
            //    int id = 0;
            //    if (rectObject.IntersectsWith(rectLT))
            //        id = 1;

            //    if (rectObject.IntersectsWith(rectRT))
            //        id = id * 10 + 2;

            //    if (rectObject.IntersectsWith(rectLB))
            //        id = id * 10 + 3;

            //    if (rectObject.IntersectsWith(rectRB))
            //        id = id * 10 + 4;

            //    return id;
            //}
        }


    }
}
