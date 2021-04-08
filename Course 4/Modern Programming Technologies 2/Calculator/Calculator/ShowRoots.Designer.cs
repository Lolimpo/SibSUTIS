namespace Calculator {
	sealed partial class ShowRoots {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.richTB_Roots = new System.Windows.Forms.RichTextBox();
			this.SuspendLayout();
			// 
			// richTB_Roots
			// 
			this.richTB_Roots.BackColor = System.Drawing.SystemColors.HighlightText;
			this.richTB_Roots.Dock = System.Windows.Forms.DockStyle.Fill;
			this.richTB_Roots.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.richTB_Roots.Location = new System.Drawing.Point(0, 0);
			this.richTB_Roots.Name = "richTB_Roots";
			this.richTB_Roots.ReadOnly = true;
			this.richTB_Roots.Size = new System.Drawing.Size(392, 243);
			this.richTB_Roots.TabIndex = 0;
			this.richTB_Roots.Text = "";
			// 
			// ShowRoots
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(392, 243);
			this.Controls.Add(this.richTB_Roots);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
			this.Name = "ShowRoots";
			this.Text = "All Roots";
			this.ResumeLayout(false);

		}

		#endregion

		public System.Windows.Forms.RichTextBox richTB_Roots;
	}
}