#include "source\BubbleSort.h"
#include "source\QuickSort.h"
#include "source\MergeSort.h" 

#pragma once

namespace Sort_WinForm_Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите значения:";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(13, 37);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(318, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 74);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Выберите порядок сортировки:";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"По возрастанию", L"По убыванию"});
			this->comboBox1->Location = System::Drawing::Point(13, 98);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(212, 24);
			this->comboBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 135);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Выберете способ сортировки:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 160);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Bubble";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(123, 159);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Quick";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(232, 158);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Merge";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 197);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Результат:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 218);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(317, 22);
			this->textBox2->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 254);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Sorting";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox1->Text->Length != 0){ 
			 array<Char>^ ar = gcnew array<Char>(1);
			  ar[0]=' ';

			  array<String^>^ as = textBox1->Text->Split(ar);
			 
			  int length = (int)Convert::ToInt64(as->Length);
			  int *mas = new int[length];
			  
			  for(int i=0; i<length; ++i)
				  mas[i] = (int)Convert::ToInt64(as[i]);

			  JacksonAlgorithms::BubbleSort(mas, 0, length-1);

			  textBox2->Text="";
			  if(comboBox1->Text == "По возрастанию")
			  for(int i=0; i<length; ++i)
				textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else if (comboBox1->Text == "По убыванию")
				  for(int i=length-1; i >= 0; --i)
					textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else MessageBox::Show("Выберете порядок сортировки!");

			  for(int i=0; i< length; ++i)
				  mas[i] = 0;
			  delete []mas;
			 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox1->Text->Length != 0){
			   array<Char>^ ar = gcnew array<Char>(1);
			  ar[0]=' ';

			  array<String^>^ as = textBox1->Text->Split(ar);
			 
			  int length = (int)Convert::ToInt64(as->Length);
			  int *mas = new int[length];
			  
			  for(int i=0; i<length; ++i)
				  mas[i] = (int)Convert::ToInt64(as[i]);

			  JacksonAlgorithms::QuickSort(mas, 0, length-1);

			  textBox2->Text="";
			  if(comboBox1->Text == "По возрастанию")
			  for(int i=0; i<length; ++i)
				textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else if (comboBox1->Text == "По убыванию")
				  for(int i=length-1; i >= 0; --i)
					textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else MessageBox::Show("Выберете порядок сортировки!");

			  for(int i=0; i< length; ++i)
				  mas[i] = 0;
			  delete []mas;
			 }
		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  if(textBox1->Text->Length != 0){
		      array<Char>^ ar = gcnew array<Char>(1);
			  ar[0]=' ';

			  array<String^>^ as = textBox1->Text->Split(ar);
			 
			  int length = (int)Convert::ToInt64(as->Length);
			  int *mas = new int[length];
			  
			  for(int i=0; i<length; ++i)
				  mas[i] = (int)Convert::ToInt64(as[i]);

			  JacksonAlgorithms::MergeSort(mas, 0, length-1);

			  textBox2->Text="";
			  if(comboBox1->Text == "По возрастанию")
			  for(int i=0; i<length; ++i)
				textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else if (comboBox1->Text == "По убыванию")
				  for(int i=length-1; i >= 0; --i)
					textBox2->Text+=(Convert::ToString(mas[i])+" "); 
			  else MessageBox::Show("Выберете порядок сортировки!");

			  for(int i=0; i< length; ++i)
				  mas[i] = 0;
			  delete []mas;
		 }
		 }
};
}

