#pragma once

namespace imageprocessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm ���K�n
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ picture_box1;
	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->picture_box1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(235, 510);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�}�ҹϤ�";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_click_1);
			// 
			// picture_box1
			// 
			this->picture_box1->Location = System::Drawing::Point(37, 24);
			this->picture_box1->Name = L"picture_box1";
			this->picture_box1->Size = System::Drawing::Size(533, 464);
			this->picture_box1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box1->TabIndex = 1;
			this->picture_box1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 576);
			this->Controls->Add(this->picture_box1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void button1_click_1(System::Object^ sender, System::EventArgs^ e) {
		// bitmap declaration
		Bitmap^ image1;
		// use openFileDialog
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		// Setup Filter�Afor bmp only
		openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*";
		// Initialization
		openFileDialog1->FileName = "";
		// Setup Title
		openFileDialog1->Title = "Ū�J�v��";
		//�]�wFilter��ܼҦ�(�̷�Filter�ơA�p���ҿ��1��ܰ_�l�X�{�����I�}�ϡA���2���All filts)
		openFileDialog1->FilterIndex = 1;


		// ShowDialog�Acheck if file is selected, if filename length is larger than 0, then load file
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName->Length > 0)
		{
			// Load file into Image1
			image1 = safe_cast<Bitmap^>(Image::FromFile(openFileDialog1->FileName));
			//�N�v����ܦbpicture_box1
			picture_box1->Image = image1;
		}
	}
	};
}
