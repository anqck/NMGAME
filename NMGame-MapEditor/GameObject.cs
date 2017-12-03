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
            WALL,
            FIREGROUND,
            COLLAPSEGROUND,
            SLIDECOLUMN,
            SWINGBAR,
            JUMPBAR,
            BLOCK,
            


            APPLE, //Cộng táo
            LAMP, //Đụng vào enemy trên màn hết máu
            HEATH, //Cộng máu
            GENIE, //Cộng điểm
            MONKEY, //Cộng điẻm
            GEM,//Cộng gem + điểm
            CHECKPOINT,

            CAMEL,

            ENEMY1,
            ENEMY2,
            ENEMY3,
            ENEMY4,
            ENEMY5, //Núp trong bình, quăng táo 0 dame
            THROWPOT,
            PEDDLER, //bán hàng

            STAIRFLAGCHANGE,
        }


        private int          mKey;
        private EObjectID    mObjID;

        private int          mPositionX, mPositionY;

        private int          mLeft;
        private int          mTop;
        private int          mRight;
        private int          mBottom;

        private MyRECT       mMoveRect;

        private int         mStairLayer;
        private int mStairLayerChangeFr;
        private int mStairLayerChangeTo;



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
                case EObjectID.ROPE:
                case EObjectID.CAMEL:
                case EObjectID.APPLE:
                case EObjectID.COLLAPSEGROUND:
                case EObjectID.JUMPBAR:
                case EObjectID.CHECKPOINT:
                case EObjectID.GEM:
                    return false;
                case EObjectID.ENEMY1:
                case EObjectID.STAIRFLAGCHANGE:
                default:
                    return true;
            }
        }

        internal static bool isObjectNeedPosition(EObjectID selectedIndex)
        {
            switch (selectedIndex)
            {
                case EObjectID.GROUND:
                case EObjectID.ROPE:
                case EObjectID.STAIR:
                case EObjectID.WALL:
                case EObjectID.STAIRFLAGCHANGE:
                case EObjectID.BLOCK:
                case EObjectID.SWINGBAR:
                case EObjectID.FIREGROUND:
                case EObjectID.SLIDECOLUMN:
                    return false;
                case EObjectID.APPLE:
                case EObjectID.CAMEL:
                case EObjectID.ENEMY1:
                case EObjectID.ENEMY2:
                case EObjectID.ENEMY3:
                case EObjectID.ENEMY4:
                case EObjectID.ENEMY5:
                case EObjectID.JUMPBAR:
                default:
                    return true;
            }
        }

        internal static bool isObjectNeedMoveRect(EObjectID selectedIndex)
        {
            switch (selectedIndex)
            {
                case EObjectID.ENEMY1:
                case EObjectID.ENEMY2:
                    return true;
                default:
                    return false;
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

        public int MStairLayer
        {
            get
            {
                return mStairLayer;
            }

            set
            {
                mStairLayer = value;
            }
        }

        public int MStairLayerChangeFr
        {
            get
            {
                return this.mStairLayerChangeFr;
            }

            set
            {
                mStairLayerChangeFr = value;
            }
        }

        public int MStairLayerChangeTo
        {
            get
            {
                return mStairLayerChangeTo;
            }

            set
            {
                mStairLayerChangeTo = value;
            }
        }

        public GameObject()
        {

        }

        public GameObject(int left, int top, int right, int bottom, EObjectID objID, int posX = 0, int posY = 0, int stairLayer = 0, int stairLayerCh1 = 0)
        {
            mLeft = left;
            mTop = top;
            mRight = right;
            mBottom = bottom;
            mObjID = objID;
            mPositionX = posX;
            mPositionY = posY;

            mStairLayer = stairLayer;

            mStairLayerChangeFr = stairLayer;
            MStairLayerChangeTo = stairLayerCh1;

            this.mMoveRect = new MyRECT(0,0,0,0);

        }
        public GameObject(int left, int top, int right, int bottom, MyRECT moveRect, EObjectID objID, int posX = 0, int posY = 0)
        {
            mLeft = left;
            mTop = top;
            mRight = right;
            mBottom = bottom;
            mObjID = objID;
            mPositionX = posX;
            mPositionY = posY;

            MStairLayer = 0;

            this.mMoveRect = moveRect;

        }

        internal Rectangle getMoveRect()
        {
            return new Rectangle(mMoveRect.MLeft, mMoveRect.MTop, mMoveRect.MRight - mMoveRect.MLeft, mMoveRect.MBottom - mMoveRect.MTop);

        }

        public MyRECT getBoundingBoxInWorldAxis()
        {
            return new MyRECT(this.MLeft,10494 -this.MTop, 10494 -  this.MBottom, this.MRight);
        }

        public MyRECT getMoveRectInWorldAxis()
        {
            return new MyRECT(mMoveRect.MLeft, 10494 - mMoveRect.MTop, 10494 - mMoveRect.MBottom, mMoveRect.MRight);
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
            switch (id)
            {
                case EObjectID.APPLE:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Apple);
                case EObjectID.COLLAPSEGROUND:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.CollapseGround);
                case EObjectID.JUMPBAR:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.JumpBar);
                case EObjectID.ENEMY1:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Enemy1);
                case EObjectID.ENEMY2:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Enemy2);
                case EObjectID.ENEMY3:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Enemy3);
                case EObjectID.ENEMY4:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Enemy4);
                case EObjectID.ENEMY5:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Enemy5);
                case EObjectID.THROWPOT:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.ThrowPotEnemy);
                case EObjectID.CHECKPOINT:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.CheckPoint);
                case EObjectID.LAMP:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Lamp);
                case EObjectID.GEM:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Gem);
                case EObjectID.PEDDLER:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Peddler);
                default:
                    return new Bitmap(NMGame_MapEditor.Properties.Resources.Camel);
            }
            
        }


    }
}
