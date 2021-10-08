#pragma once

namespace imageprocessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
			this->button1->Text = L"開啟圖片";
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
		// Setup Filter，for bmp only
		openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*";
		// Initialization
		openFileDialog1->FileName = "";
		// Setup Title
		openFileDialog1->Title = "讀入影像";
		//設定Filter選擇模式(依照Filter數，如本例選擇1表示起始出現的為點陣圖，選擇2表示All filts)
		openFileDialog1->FilterIndex = 1;


		// ShowDialog，check if file is selected, if filename length is larger than 0, then load file
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName->Length > 0)
		{
			// Load file into Image1
			image1 = safe_cast<Bitmap^>(Image::FromFile(openFileDialog1->FileName));
			//將影像顯示在picture_box1
			picture_box1->Image = image1;
		}
	}
	};
}
