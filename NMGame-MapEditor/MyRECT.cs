using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMGame_MapEditor
{
    public class MyRECT
    {
        private int mLeft;
        private int mRight;
        private int mTop;
        private int mBottom;

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

        public MyRECT()
        {

        }

        public MyRECT(int left, int top, int bottom, int right)
        {
            mLeft = left;
            mTop = top;
            mBottom = bottom;
            mRight = right;
        }

        //Kiểm tra xem hcn rect có nằm trong hcn this không
        public bool Contains(MyRECT rect)
        {
            return ((mLeft <= rect.mLeft) && (mRight >= rect.MRight) && (mTop >= rect.mTop) && (rect.mBottom >= mBottom));
        }

        //Kiểm tra xem hcn rect có giao với hcn this không
        public bool Intersects(MyRECT rect)
        {
            return ((mLeft <= rect.mLeft) || (mRight >= rect.MRight) || (mTop >= rect.mTop) || (rect.mBottom >= mBottom));
        }

    }


}
