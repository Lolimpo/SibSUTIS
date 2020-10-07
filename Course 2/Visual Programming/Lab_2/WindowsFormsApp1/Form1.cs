using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Color historyColor;
        bool drawing;
        int historyCounter;
        GraphicsPath currentPath;
        Point oldLocation;
        Pen currentPen;

        List<Image> History;

        public Form1()
        {
            InitializeComponent();
            drawing = false; 
            currentPen = new Pen(Color.Black);
            History = new List<Image>(); 
        }

        private void styleToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void dotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            solidToolStripMenuItem.Checked = false;
            dashDotDotToolStripMenuItem.Checked = false;
            dotToolStripMenuItem.Checked = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                var result = MessageBox.Show("Сохранить текущее изображение перед созданием нового рисунка?", "Предупреждение", MessageBoxButtons.YesNoCancel);

                switch (result)
                {
                    case DialogResult.No: break;
                    case DialogResult.Yes: saveToolStripMenuItem_Click(sender, e); break;
                    case DialogResult.Cancel: return;
                }
            }
            History.Clear();
            historyCounter = 0;
            historyColor = Color.Black;
            Bitmap pic = new Bitmap(750, 500);
                pictureBox1.Image = pic;
            History.Add(new Bitmap(pictureBox1.Image));
                Graphics g = Graphics.FromImage(pictureBox1.Image);
                g.Clear(Color.White);
                g.DrawImage(pictureBox1.Image, 0, 0, 750, 500);
            }

            private void saveToolStripMenuItem_Click(object sender, EventArgs e)
            {
                SaveFileDialog SaveDlg = new SaveFileDialog();
                SaveDlg.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
                SaveDlg.Title = "Save an Image File";
                SaveDlg.FilterIndex = 4;
                SaveDlg.ShowDialog();

                if (SaveDlg.FileName != "")     //Если введено не пустое имя 
                {
                    System.IO.FileStream fs =
                       (System.IO.FileStream)SaveDlg.OpenFile();

                    switch (SaveDlg.FilterIndex)
                    {
                        case 1: this.pictureBox1.Image.Save(fs, ImageFormat.Jpeg); break;
                        case 2: this.pictureBox1.Image.Save(fs, ImageFormat.Bmp); break;
                        case 3:
                            this.pictureBox1.Image.Save(fs, ImageFormat.Gif); break;
                        case 4:
                            this.pictureBox1.Image.Save(fs, ImageFormat.Png); break;
                    }

                    fs.Close();
                }

            }

            private void openToolStripMenuItem_Click(object sender, EventArgs e)
            {
                OpenFileDialog OP = new OpenFileDialog();
                OP.Filter = "JPEG Image|*.jpg|Bitmap Image|*.bmp|GIF Image|*.gif|PNG Image|*.png";
                OP.Title = "Open an Image File";
                OP.FilterIndex = 1; //По умолчанию будет выбрано первое расширение *.jpg И, когда пользователь укажет нужный путь к картинке, ее нужно будет загрузить в PictureBox: 
                if (OP.ShowDialog() != DialogResult.Cancel) pictureBox1.Load(OP.FileName);
                pictureBox1.AutoSize = true;

            }

            private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
            {
                if (pictureBox1.Image == null)
                {
                    MessageBox.Show("Сначала создайте новый файл!"); return;
                }
                if (e.Button == MouseButtons.Left)
                {
                    currentPen = new Pen(historyColor);
                 currentPen.Width = trackBar1.Value;
                if (solidToolStripMenuItem.Checked)
                    currentPen.DashStyle = DashStyle.Solid;
                if (dotToolStripMenuItem.Checked)
                    currentPen.DashStyle = DashStyle.Dot;
                if (dashDotDotToolStripMenuItem.Checked)
                    currentPen.DashStyle = DashStyle.DashDotDot;
                drawing = true; oldLocation = e.Location;
                currentPath = new GraphicsPath();
                }
            if (e.Button == MouseButtons.Right)
            {
                historyColor = currentPen.Color;
                currentPen = new Pen(Color.White);
                currentPen.Width = trackBar1.Value;
                drawing = true; oldLocation = e.Location;
                currentPath = new GraphicsPath();
            }
        }

            private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
            {
            History.RemoveRange(historyCounter + 1, History.Count - historyCounter - 1);
            History.Add(new Bitmap(pictureBox1.Image));
            if (historyCounter + 1 < 10) historyCounter++;
            if (History.Count - 1 == 10) History.RemoveAt(0);
            drawing = false;
                try
                {
                    currentPath.Dispose();
                }
                catch { };

            }

            private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
            {
            label1.Text = e.X.ToString() + ", " + e.Y.ToString();
            if (drawing)
                {
                    Graphics g = Graphics.FromImage(pictureBox1.Image); currentPath.AddLine(oldLocation, e.Location);
                    g.DrawPath(currentPen, currentPath); oldLocation = e.Location;
                    g.Dispose();
                    pictureBox1.Invalidate();
                }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
        }

        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (History.Count != 0 && historyCounter != 0)
            {
                pictureBox1.Image = new Bitmap(History[--historyCounter]);
            }
            else MessageBox.Show("История пуста");
        }

        private void renoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (historyCounter < History.Count - 1)
            {
                pictureBox1.Image = new Bitmap(History[++historyCounter]);
            }
            else MessageBox.Show("История пуста");
        }

        private void solidToolStripMenuItem_Click(object sender, EventArgs e)
        {
            solidToolStripMenuItem.Checked = true;
            dashDotDotToolStripMenuItem.Checked = false;
            dotToolStripMenuItem.Checked = false;
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void penToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void dashDotDotToolStripMenuItem_Click(object sender, EventArgs e)
        {
            solidToolStripMenuItem.Checked = false;
            dashDotDotToolStripMenuItem.Checked = true;
            dotToolStripMenuItem.Checked = false;
        }
    }
    }
