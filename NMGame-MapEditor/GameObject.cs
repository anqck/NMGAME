using System;
using System.Collections.Generic;
using System.Drawing;
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
            STAIR,
            CAMEL,
            ENEMY
        }


        private int          mKey;
        private EObjectID    mObjID;

        private int          mPositionX, mPositionY;

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

        internal static bool isObjectNeedDrawBoundingRect(EObjectID selectedIndex)
        {
            switch (selectedIndex)
            {
                case EObjectID.GROUND:
                case EObjectID.CAMEL:
                    return false;
                case EObjectID.ENEMY:
                default:
                    return true;
            }
        }

        internal static bool isObjectNeedPosition(EObjectID selectedIndex)
        {
            switch (selectedIndex)
            {
                case EObjectID.GROUND:
                
                    return false;
                case EObjectID.CAMEL:
                case EObjectID.ENEMY:
                default:
                    return true;
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

        public int MPositionX
        {
            get
            {
                return mPositionX;
            }

            set
            {
                mPositionX = value;
            }
        }

        public int MPositionY
        {
            get
            {
                return mPositionY;
            }

            set
            {
                mPositionY = value;
            }
        }

        public GameObject()
        {

        }
        public GameObject(int left, int top, int right, int bottom, EObjectID objID, int posX = 0, int posY = 0)
        {
            mLeft = left;
            mTop = top;
            mRight = right;
            mBottom = bottom;
            mObjID = objID;
            mPositionX = posX;
            mPositionY = posY;

        }



        public MyRECT getBoundingBoxInWorldAxis()
        {
            return new MyRECT(this.MLeft, 9542 - this.MTop, 9542 - this.MBottom, this.MRight);
        }

        internal static bool isObjectNeedPosition(GameObject obj)
        {
            return isObjectNeedPosition(obj.mObjID);
        }

        internal Rectangle getBoundingRect()
        {
            return new Rectangle(this.MLeft, this.MTop, this.MRight - this.MLeft, this.MBottom - this.MTop);

        }

        internal static Bitmap GetObjectImg(EObjectID id)
        {
            return new Bitmap(NMGame_MapEditor.Properties.Resources.Camel);
        }


    }
}
