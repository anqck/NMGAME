using System;
using System.Windows.Forms;

namespace NMGame_MapEditor
{
    partial class MapEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnNew = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.lblzoom = new System.Windows.Forms.Label();
            this.btnExport = new System.Windows.Forms.Button();
            this.btnImport = new System.Windows.Forms.Button();
            this.btnBuildQuadTree = new System.Windows.Forms.Button();
            this.listView1 = new System.Windows.Forms.ListView();
            this.clmKey = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.clmPos = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.clmRECT = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.clmType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnEdit = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.grpObjectInfo = new System.Windows.Forms.GroupBox();
            this.btnDrawRectangle = new System.Windows.Forms.Button();
            this.btnPlaceObject = new System.Windows.Forms.Button();
            this.grpPosition = new System.Windows.Forms.GroupBox();
            this.txtPosY = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.txtPosX = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.cbObjType = new System.Windows.Forms.ComboBox();
            this.grpBounded = new System.Windows.Forms.GroupBox();
            this.txtBottom = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtRight = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtTop = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtLeft = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.mWorldSpace = new NMGame_MapEditor.ImageView();
            this.statusStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel2.SuspendLayout();
            this.grpObjectInfo.SuspendLayout();
            this.grpPosition.SuspendLayout();
            this.grpBounded.SuspendLayout();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnNew
            // 
            this.btnNew.Location = new System.Drawing.Point(10, 309);
            this.btnNew.Name = "btnNew";
            this.btnNew.Size = new System.Drawing.Size(80, 34);
            this.btnNew.TabIndex = 1;
            this.btnNew.Text = "New";
            this.btnNew.UseVisualStyleBackColor = true;
            this.btnNew.Click += new System.EventHandler(this.btnNew_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 843);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1559, 25);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(151, 20);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.panel3);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel1.Location = new System.Drawing.Point(1159, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(400, 843);
            this.panel1.TabIndex = 3;
            // 
            // panel3
            // 
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel3.Controls.Add(this.lblzoom);
            this.panel3.Controls.Add(this.btnExport);
            this.panel3.Controls.Add(this.btnImport);
            this.panel3.Controls.Add(this.btnBuildQuadTree);
            this.panel3.Controls.Add(this.listView1);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel3.Location = new System.Drawing.Point(0, 351);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(396, 488);
            this.panel3.TabIndex = 3;
            // 
            // lblzoom
            // 
            this.lblzoom.AutoSize = true;
            this.lblzoom.Location = new System.Drawing.Point(22, 388);
            this.lblzoom.Name = "lblzoom";
            this.lblzoom.Size = new System.Drawing.Size(46, 17);
            this.lblzoom.TabIndex = 8;
            this.lblzoom.Text = "label1";
            // 
            // btnExport
            // 
            this.btnExport.Location = new System.Drawing.Point(203, 382);
            this.btnExport.Name = "btnExport";
            this.btnExport.Size = new System.Drawing.Size(75, 23);
            this.btnExport.TabIndex = 7;
            this.btnExport.Text = "Export";
            this.btnExport.UseVisualStyleBackColor = true;
            this.btnExport.Click += new System.EventHandler(this.btnExport_Click);
            // 
            // btnImport
            // 
            this.btnImport.Location = new System.Drawing.Point(111, 382);
            this.btnImport.Name = "btnImport";
            this.btnImport.Size = new System.Drawing.Size(75, 23);
            this.btnImport.TabIndex = 6;
            this.btnImport.Text = "Import";
            this.btnImport.UseVisualStyleBackColor = true;
            this.btnImport.Click += new System.EventHandler(this.btnImport_Click);
            // 
            // btnBuildQuadTree
            // 
            this.btnBuildQuadTree.Location = new System.Drawing.Point(127, 431);
            this.btnBuildQuadTree.Name = "btnBuildQuadTree";
            this.btnBuildQuadTree.Size = new System.Drawing.Size(131, 50);
            this.btnBuildQuadTree.TabIndex = 5;
            this.btnBuildQuadTree.Text = "BuildQuadTree";
            this.btnBuildQuadTree.UseVisualStyleBackColor = true;
            this.btnBuildQuadTree.Click += new System.EventHandler(this.btnBuildQuadTree_Click);
            // 
            // listView1
            // 
            this.listView1.CheckBoxes = true;
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.clmKey,
            this.clmPos,
            this.clmRECT,
            this.clmType});
            this.listView1.FullRowSelect = true;
            this.listView1.Location = new System.Drawing.Point(10, 19);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(374, 333);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.ItemChecked += new System.Windows.Forms.ItemCheckedEventHandler(this.listView1_ItemChecked);
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            // 
            // clmKey
            // 
            this.clmKey.Text = "Idx";
            this.clmKey.Width = 40;
            // 
            // clmPos
            // 
            this.clmPos.Text = "Position";
            this.clmPos.Width = 92;
            // 
            // clmRECT
            // 
            this.clmRECT.Text = "RECT [L , T , R , B]";
            this.clmRECT.Width = 147;
            // 
            // clmType
            // 
            this.clmType.Text = "Type";
            this.clmType.Width = 87;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.btnSave);
            this.panel2.Controls.Add(this.btnEdit);
            this.panel2.Controls.Add(this.btnDelete);
            this.panel2.Controls.Add(this.grpObjectInfo);
            this.panel2.Controls.Add(this.btnNew);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(396, 351);
            this.panel2.TabIndex = 2;
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(298, 309);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(80, 34);
            this.btnSave.TabIndex = 4;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnEdit
            // 
            this.btnEdit.Location = new System.Drawing.Point(106, 309);
            this.btnEdit.Name = "btnEdit";
            this.btnEdit.Size = new System.Drawing.Size(80, 34);
            this.btnEdit.TabIndex = 3;
            this.btnEdit.Text = "Edit";
            this.btnEdit.UseVisualStyleBackColor = true;
            this.btnEdit.Click += new System.EventHandler(this.btnEdit_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(203, 309);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(80, 34);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // grpObjectInfo
            // 
            this.grpObjectInfo.Controls.Add(this.btnDrawRectangle);
            this.grpObjectInfo.Controls.Add(this.btnPlaceObject);
            this.grpObjectInfo.Controls.Add(this.grpPosition);
            this.grpObjectInfo.Controls.Add(this.label6);
            this.grpObjectInfo.Controls.Add(this.cbObjType);
            this.grpObjectInfo.Controls.Add(this.grpBounded);
            this.grpObjectInfo.Location = new System.Drawing.Point(10, 12);
            this.grpObjectInfo.Name = "grpObjectInfo";
            this.grpObjectInfo.Size = new System.Drawing.Size(374, 278);
            this.grpObjectInfo.TabIndex = 0;
            this.grpObjectInfo.TabStop = false;
            this.grpObjectInfo.Text = "Object Information:";
            // 
            // btnDrawRectangle
            // 
            this.btnDrawRectangle.Location = new System.Drawing.Point(178, 244);
            this.btnDrawRectangle.Name = "btnDrawRectangle";
            this.btnDrawRectangle.Size = new System.Drawing.Size(121, 28);
            this.btnDrawRectangle.TabIndex = 11;
            this.btnDrawRectangle.Text = "Draw Rectangle";
            this.btnDrawRectangle.UseVisualStyleBackColor = true;
            this.btnDrawRectangle.Click += new System.EventHandler(this.btnDrawRectangle_Click);
            // 
            // btnPlaceObject
            // 
            this.btnPlaceObject.Location = new System.Drawing.Point(54, 244);
            this.btnPlaceObject.Name = "btnPlaceObject";
            this.btnPlaceObject.Size = new System.Drawing.Size(112, 28);
            this.btnPlaceObject.TabIndex = 5;
            this.btnPlaceObject.Text = "Place Object";
            this.btnPlaceObject.UseVisualStyleBackColor = true;
            this.btnPlaceObject.Click += new System.EventHandler(this.btnPlaceObject_Click);
            // 
            // grpPosition
            // 
            this.grpPosition.Controls.Add(this.txtPosY);
            this.grpPosition.Controls.Add(this.label8);
            this.grpPosition.Controls.Add(this.txtPosX);
            this.grpPosition.Controls.Add(this.label9);
            this.grpPosition.Location = new System.Drawing.Point(6, 67);
            this.grpPosition.Name = "grpPosition";
            this.grpPosition.Size = new System.Drawing.Size(362, 61);
            this.grpPosition.TabIndex = 10;
            this.grpPosition.TabStop = false;
            this.grpPosition.Text = "Object Position:";
            // 
            // txtPosY
            // 
            this.txtPosY.Location = new System.Drawing.Point(231, 26);
            this.txtPosY.Name = "txtPosY";
            this.txtPosY.Size = new System.Drawing.Size(112, 22);
            this.txtPosY.TabIndex = 5;
            this.txtPosY.TextChanged += new System.EventHandler(this.txtPosY_TextChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(204, 29);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(21, 17);
            this.label8.TabIndex = 4;
            this.label8.Text = "Y:";
            // 
            // txtPosX
            // 
            this.txtPosX.Location = new System.Drawing.Point(48, 26);
            this.txtPosX.Name = "txtPosX";
            this.txtPosX.Size = new System.Drawing.Size(112, 22);
            this.txtPosX.TabIndex = 2;
            this.txtPosX.TextChanged += new System.EventHandler(this.txtPosX_TextChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(16, 26);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(21, 17);
            this.label9.TabIndex = 3;
            this.label9.Text = "X:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(22, 40);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(89, 17);
            this.label6.TabIndex = 6;
            this.label6.Text = "Object Type:";
            // 
            // cbObjType
            // 
            this.cbObjType.FormattingEnabled = true;
            this.cbObjType.Location = new System.Drawing.Point(117, 37);
            this.cbObjType.Name = "cbObjType";
            this.cbObjType.Size = new System.Drawing.Size(231, 24);
            this.cbObjType.TabIndex = 5;
            this.cbObjType.SelectedIndexChanged += new System.EventHandler(this.cbObjType_SelectedIndexChange);
            // 
            // grpBounded
            // 
            this.grpBounded.Controls.Add(this.txtBottom);
            this.grpBounded.Controls.Add(this.label4);
            this.grpBounded.Controls.Add(this.txtRight);
            this.grpBounded.Controls.Add(this.label5);
            this.grpBounded.Controls.Add(this.txtTop);
            this.grpBounded.Controls.Add(this.label3);
            this.grpBounded.Controls.Add(this.txtLeft);
            this.grpBounded.Controls.Add(this.label2);
            this.grpBounded.Location = new System.Drawing.Point(6, 134);
            this.grpBounded.Name = "grpBounded";
            this.grpBounded.Size = new System.Drawing.Size(362, 106);
            this.grpBounded.TabIndex = 4;
            this.grpBounded.TabStop = false;
            this.grpBounded.Text = "Bounded Rectangle:";
            // 
            // txtBottom
            // 
            this.txtBottom.Location = new System.Drawing.Point(231, 56);
            this.txtBottom.Name = "txtBottom";
            this.txtBottom.Size = new System.Drawing.Size(112, 22);
            this.txtBottom.TabIndex = 9;
            this.txtBottom.TextChanged += new System.EventHandler(this.txt_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(169, 59);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 17);
            this.label4.TabIndex = 8;
            this.label4.Text = "Bottom:";
            // 
            // txtRight
            // 
            this.txtRight.Location = new System.Drawing.Point(48, 59);
            this.txtRight.Name = "txtRight";
            this.txtRight.Size = new System.Drawing.Size(112, 22);
            this.txtRight.TabIndex = 6;
            this.txtRight.TextChanged += new System.EventHandler(this.txt_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 59);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(45, 17);
            this.label5.TabIndex = 7;
            this.label5.Text = "Right:";
            // 
            // txtTop
            // 
            this.txtTop.Location = new System.Drawing.Point(231, 26);
            this.txtTop.Name = "txtTop";
            this.txtTop.Size = new System.Drawing.Size(112, 22);
            this.txtTop.TabIndex = 5;
            this.txtTop.TextChanged += new System.EventHandler(this.txt_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(169, 26);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "Top:";
            // 
            // txtLeft
            // 
            this.txtLeft.Location = new System.Drawing.Point(48, 26);
            this.txtLeft.Name = "txtLeft";
            this.txtLeft.Size = new System.Drawing.Size(112, 22);
            this.txtLeft.TabIndex = 2;
            this.txtLeft.TextChanged += new System.EventHandler(this.txt_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 26);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(36, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Left:";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.mWorldSpace);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel4.Location = new System.Drawing.Point(0, 0);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(1159, 843);
            this.panel4.TabIndex = 4;
            // 
            // mWorldSpace
            // 
            this.mWorldSpace.Cursor = System.Windows.Forms.Cursors.Cross;
            this.mWorldSpace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mWorldSpace.Location = new System.Drawing.Point(0, 0);
            this.mWorldSpace.MImage = null;
            this.mWorldSpace.Name = "mWorldSpace";
            this.mWorldSpace.Rect = new System.Drawing.Rectangle(0, 0, 0, 0);
            this.mWorldSpace.Size = new System.Drawing.Size(1159, 843);
            this.mWorldSpace.TabIndex = 0;
            this.mWorldSpace.KeyDown += new System.Windows.Forms.KeyEventHandler(this.mWorldSpace_KeyDown);
            this.mWorldSpace.MouseDown += new System.Windows.Forms.MouseEventHandler(this.mWorldSpace_MouseDown);
            this.mWorldSpace.MouseMove += new System.Windows.Forms.MouseEventHandler(this.mWorldSpace_MouseMove);
            this.mWorldSpace.MouseUp += new System.Windows.Forms.MouseEventHandler(this.mWorldSpace_MouseUp);
        
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1559, 868);
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.statusStrip1);
            this.Name = "MapEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.MapEditor_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyDown);
            this.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseWheel);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.grpObjectInfo.ResumeLayout(false);
            this.grpObjectInfo.PerformLayout();
            this.grpPosition.ResumeLayout(false);
            this.grpPosition.PerformLayout();
            this.grpBounded.ResumeLayout(false);
            this.grpBounded.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

      






        #endregion

        private ImageView mWorldSpace;
        private System.Windows.Forms.Button btnNew;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.GroupBox grpObjectInfo;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnEdit;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cbObjType;
        private System.Windows.Forms.GroupBox grpBounded;
        private System.Windows.Forms.TextBox txtBottom;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtRight;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtTop;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtLeft;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader clmRECT;
        private System.Windows.Forms.ColumnHeader clmType;
        private System.Windows.Forms.Button btnBuildQuadTree;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.GroupBox grpPosition;
        private System.Windows.Forms.TextBox txtPosY;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox txtPosX;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button btnDrawRectangle;
        private System.Windows.Forms.Button btnPlaceObject;
        private System.Windows.Forms.ColumnHeader clmPos;
        private System.Windows.Forms.Button btnExport;
        private System.Windows.Forms.Button btnImport;
        private System.Windows.Forms.ColumnHeader clmKey;
        private System.Windows.Forms.Label lblzoom;
    }
}

