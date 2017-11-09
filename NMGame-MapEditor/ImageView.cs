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

        public void ClearRectangle()
        {
            Rect = new Rectangle(0,0,0,0);
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

            Pen blackPen = new Pen(Color.Red, 3);

            e.Graphics.DrawRectangle(blackPen, Rect);
        }


    }
}
