#pragma once

namespace MatrixTranspouse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Button^  button1;





























	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"¬ведите вашу матрицу:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(22, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(57, 38);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(85, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(57, 38);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(148, 32);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(57, 38);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(21, 76);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(57, 38);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(84, 76);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(57, 38);
			this->textBox5->TabIndex = 5;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(148, 76);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(57, 38);
			this->textBox6->TabIndex = 6;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(21, 120);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(57, 38);
			this->textBox7->TabIndex = 7;
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(85, 120);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(57, 38);
			this->textBox8->TabIndex = 8;
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(148, 120);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(57, 38);
			this->textBox9->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 172);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 31);
			this->button1->TabIndex = 10;
			this->button1->Text = L"“ранспонировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(227, 215);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Transpouse";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if( textBox1->Text->Length &&
				textBox2->Text->Length &&
				textBox3->Text->Length &&
				textBox4->Text->Length &&
				textBox5->Text->Length &&
				textBox6->Text->Length &&
				textBox7->Text->Length &&
				textBox8->Text->Length &&
				textBox9->Text->Length){

				String^ s2 = textBox2->Text;
				String^ s3 = textBox3->Text;
				String^ s6 = textBox6->Text;
				
				textBox2->Text = textBox4->Text;
				textBox3->Text = textBox7->Text;
				textBox6->Text = textBox8->Text;

				textBox4->Text = s2; 
				textBox7->Text = s3;
				textBox8->Text = s6;
				}
			else
				MessageBox::Show("¬ведите матрицу целиком!");
		 }
};
}

