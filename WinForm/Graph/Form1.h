#pragma once

namespace lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 15);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(670, 452);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 481);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Ãðàôèêè y=f(x)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private:
int l, b, h, w;
static int n = 1;

	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

             h = pictureBox1->Height;            // Øèðèíà
			 w = pictureBox1->Width;             // Âûñîòà

             // Osi
			 e->Graphics->DrawLine(Pens::Black,0,h/2,w,h/2);
             e->Graphics->DrawLine(Pens::Black,w/2,0,w/2,h);
   
             // Strelki
   
             e->Graphics->DrawLine(Pens::Black,w-25,h/2+8,w,h/2);
             e->Graphics->DrawLine(Pens::Black,w-25,h/2-8,w,h/2);
             e->Graphics->DrawLine(Pens::Black,w/2-8,25,w/2,0);
             e->Graphics->DrawLine(Pens::Black,w/2+8,25,w/2,0);
  
   
             // Podpisi
             e->Graphics->DrawString("X",this->Font,Brushes::Black,w-15,h/2-25);
             e->Graphics->DrawString("Y",this->Font,Brushes::Black,w/2-25,5);
  
			double x1, y1, x, y;
			
			/* First part */
			double fi, p;
			const double pi = 3.1415; 
			const int n = 10;			// koli4estvo vitkov
			const double dFi = 0.001;     // step
	
			fi = 0;
			p = fi / 2;
			x1 = p * Math::Cos(fi);
			y1 = p * Math::Sin(fi);

			const int mx = 8, my = 8;        // mashtab po x i y
   
			while(fi <= 2*pi*n)
			{
				p = fi / 2;
			    x = p * Math::Cos(fi);
				y = p * Math::Sin(fi);
				e->Graphics->DrawLine(Pens::Blue,(int)(x1*mx+w/2),(int)(h/2-y1*my),(int)(x*mx+w/2),(int)(h/2-y*my));
		    	x1 = x;
				y1 = y;
				fi+=dFi;
			}

		   /*  Second part */

		  double Oz1 = 0, Oz2 = 1;
		  double Ox1 = -Math::Sqrt(3)/2, Ox = -1/2;
		  double Oy1 = Math::Sqrt(3)/2, Oy2 = -1/2;
			
		  /* Main Formula
			 z = xy + ln (x+y) */
    }
};
}
