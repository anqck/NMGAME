using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NMGame_MapEditor
{
   

    public partial class ImageView : UserControl
    {
        private Image mImage;

        public Action callBack;

        private Rectangle rect = new Rectangle(0, 0, 0, 0);

        private Image mObject;
        private int mObjectX, mObjectY;

        private List<GameObject> drawObject;
        private List<Rectangle> mListRect;
        private List<Image> mListImg;


        public ImageView()
        {
            InitializeComponent();
        }

        public Image MImage
        {
            get
            {
                return mImage;
            }

            set
            {
                mImage = value;
                if (value == null) this.AutoScrollMinSize = new Size(0, 0);
                else
                {
                    var size = value.Size;
                    using (var gr = this.CreateGraphics())
                    {
                        size.Width = (int)(size.Width * gr.DpiX / value.HorizontalResolution);
                        size.Height = (int)(size.Height * gr.DpiY / value.VerticalResolution);

                        
                    }
                    this.AutoScrollMinSize = size;

                }
                this.Invalidate();
            }
        }

        public Rectangle Rect
        {
            get
            {
                return rect;
            }

            set
            {
                rect = value;
            }
        }



        public void SetImageObject(Bitmap img, int X, int y)
        {
            if (img == null)
                return;

            this.mObject = img;
            this.mObjectX = X;
            this.mObjectY = y;

            this.Invalidate();
        }

        public void ClearObjectImage()
        {
            this.mObject = null;

            this.Invalidate();
        }

        public void ClearRectangle()
        {
            Rect = new Rectangle(0,0,0,0);
            this.Invalidate();
        }
        public void DrawRectangle(int x1, int y1, int x2, int y2)
        {
            // Create pen.

            // Create rectangle.
            if ((x2 > x1)&&(y2>y1))            
                Rect = new Rectangle(x1,y1, (x2 - x1),(y2-y1));
            else if ((x2 < x1) && (y2 > y1))
                Rect = new Rectangle(x2, y1, (x1 - x2), (y2 - y1));
            else if ((x2 > x1) && (y2 < y1))
                Rect = new Rectangle(x1, y2, (x2 - x1), (y1 - y2));
            else if ((x1 > x2) && (y1 > y2))
                Rect = new Rectangle(x2, y2, (x1 - x2), (y1 - y2));

            // Draw rectangle to screen.

        }

        private void ImageView_Load(object sender, EventArgs e)
        {
            this.DoubleBuffered = true;
           
        }

        private void ImageView_Paint(object sender, PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;


            graphics.TranslateTransform(this.AutoScrollPosition.X, this.AutoScrollPosition.Y);

            if (mImage != null)
            {               
                graphics.DrawImage(mImage, 0, 0);
            }

            if (mObject != null)
            {
                graphics.DrawImage(mObject, mObjectX, mObjectY);
            }

            if(drawObject != null)
            {
                if(drawObject.Count != 0)
                {
                    foreach (GameObject obj in drawObject)
                    {
                        e.Graphics.DrawRectangle(new Pen(Color.White, 3), obj.getBoundingRect());

                        if (GameObject.isObjectNeedPosition(obj) == true)
                        {
                            Bitmap img = GameObject.GetObjectImg(obj.MObjID);
                            graphics.DrawImage(img, obj.MPositionX - img.Size.Width / 2, obj.MPositionY -  img.Size.Height);
                        }
                    }
                }


            }



            

            e.Graphics.DrawRectangle(new Pen(Color.Red, 3), Rect);
        }

        internal void VisualizeObject(GameObject obj)
        {
            DrawRectangle(obj.MLeft, obj.MTop, obj.MRight, obj.MBottom);

            if(GameObject.isObjectNeedPosition(obj) == true)
            {
                Bitmap img = GameObject.GetObjectImg(obj.MObjID);
                SetImageObject(img, obj.MPositionX - img.Size.Width / 2, obj.MPositionY - img.Size.Height);
                    
            }
            else
            {
                mObject = null;
            }

            this.Invalidate();
        }

        internal void VisualizeListObject(List<GameObject> obj)
        {
            drawObject = new List<GameObject>(obj); 
            this.Invalidate();
        }
    }
}
