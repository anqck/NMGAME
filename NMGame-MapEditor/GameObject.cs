using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMGame_MapEditor
{
    public class GameObject
    {
        public enum EObjectID
        {
            GROUND,
            ROPE,
            STAIR
        }


        private int          mKey;
        private EObjectID    mObjID;        

        private int          mLeft;
        private int          mTop;
        private int          mRight;
        private int          mBottom;





     
        public int MLeft
        {
            get
            {
                return mLeft;
            }

            set
            {
                mLeft = value;
            }
        }

        public int MTop
        {
            get
            {
                return mTop;
            }

            set
            {
                mTop = value;
            }
        }

        public int MRight
        {
            get
            {
                return mRight;
            }

            set
            {
                mRight = value;
            }
        }

        public int MBottom
        {
            get
            {
                return mBottom;
            }

            set
            {
                mBottom = value;
            }
        }

        internal EObjectID MObjID
        {
            get
            {
                return mObjID;
            }

            set
            {
                mObjID = value;
            }
        }

        public int MKey
        {
            get
            {
                return mKey;
            }

            set
            {
                mKey = value;
            }
        }

        public GameObject()
        {

        }
        public GameObject(int left, int top, int right, int bottom, EObjectID objID)
        {
            mLeft = left;
            mTop = top;
            mRight = right;
            mBottom = bottom;
            mObjID = objID;

        }

        public MyRECT getBoundingBoxInWorldAxis()
        {
            return new MyRECT(this.MLeft, 9542 - this.MTop, 9542 - this.MBottom, this.MRight);
        }



  
    }
}
