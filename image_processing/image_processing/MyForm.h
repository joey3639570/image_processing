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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ picture_box2;
	private: System::Windows::Forms::Button^ buttonRed;
	private: System::Windows::Forms::Button^ buttonGreen;
	private: System::Windows::Forms::Button^ buttonBlue;
	private: System::Windows::Forms::Button^ buttonGray;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->picture_box2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonRed = (gcnew System::Windows::Forms::Button());
			this->buttonBlue = (gcnew System::Windows::Forms::Button());
			this->buttonGreen = (gcnew System::Windows::Forms::Button());
			this->buttonGray = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(192, 512);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"開啟圖片";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_click_1);
			// 
			// picture_box1
			// 
			this->picture_box1->Location = System::Drawing::Point(32, 24);
			this->picture_box1->Name = L"picture_box1";
			this->picture_box1->Size = System::Drawing::Size(448, 448);
			this->picture_box1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box1->TabIndex = 1;
			this->picture_box1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(704, 512);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Undo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// picture_box1
			// 
			this->picture_box2->Location = System::Drawing::Point(544, 24);
			this->picture_box2->Name = L"picture_box2";
			this->picture_box2->Size = System::Drawing::Size(448, 448);
			this->picture_box2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box2->TabIndex = 3;
			this->picture_box2->TabStop = false;
			// 
			// Red Extraction Button
			// 
			this->buttonRed->Location = System::Drawing::Point(32, 576);
			this->buttonRed->Name = L"buttonRed";
			this->buttonRed->Size = System::Drawing::Size(96, 32);
			this->buttonRed->TabIndex = 4;
			this->buttonRed->Text = L"Red Extraction";
			this->buttonRed->UseVisualStyleBackColor = true;
			this->buttonRed->Click += gcnew System::EventHandler(this, &MyForm::buttonRed_Click);
			// 
			// Blue Extraction Button
			// 
			this->buttonBlue->Location = System::Drawing::Point(32, 640);
			this->buttonBlue->Name = L"buttonBlue";
			this->buttonBlue->Size = System::Drawing::Size(96, 32);
			this->buttonBlue->TabIndex = 5;
			this->buttonBlue->Text = L"Blue Extraction";
			this->buttonBlue->UseVisualStyleBackColor = true;
			this->buttonBlue->Click += gcnew System::EventHandler(this, &MyForm::buttonBlue_Click);
			// 
			// Green Extraction Button
			// 
			this->buttonGreen->Location = System::Drawing::Point(160, 576);
			this->buttonGreen->Name = L"buttonGreen";
			this->buttonGreen->Size = System::Drawing::Size(96, 32);
			this->buttonGreen->TabIndex = 6;
			this->buttonGreen->Text = L"Green Extraction";
			this->buttonGreen->UseVisualStyleBackColor = true;
			this->buttonGreen->Click += gcnew System::EventHandler(this, &MyForm::buttonGreen_Click);
			// 
			// Gray scale Button
			// 
			this->buttonGray->Location = System::Drawing::Point(160, 640);
			this->buttonGray->Name = L"buttonGray";
			this->buttonGray->Size = System::Drawing::Size(96, 32);
			this->buttonGray->TabIndex = 7;
			this->buttonGray->Text = L"Gray Scale";
			this->buttonGray->UseVisualStyleBackColor = true;
			this->buttonGray->Click += gcnew System::EventHandler(this, &MyForm::buttonGray_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->Controls->Add(this->picture_box1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->picture_box2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonRed);
			this->Controls->Add(this->buttonGreen);
			this->Controls->Add(this->buttonBlue);
			this->Controls->Add(this->buttonGray);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->EndInit();
			this->ResumeLayout(false);

		}
		// Bitmap object for the picture you opened宣告Bitmap 儲存開啟的圖
		Bitmap^ image1;

		// BitmapData object data for pixel
		Imaging::BitmapData^ ImageData1;

		// Image area
		Rectangle rect;

		// int pointer for calculation
		IntPtr ptr, GrayResultPtr, RedResultPtr, GreenResultPtr, BlueResultPtr;

		// Byte pointer
		Byte* p;
		Byte* Gr;
		Byte* G;
		Byte* R;
		Byte* B;

#pragma endregion
	private: System::Void button1_click_1(System::Object^ sender, System::EventArgs^ e) {
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
			//設定rect
			rect = Rectangle(0, 0, image1->Width, image1->Height);
			//將影像顯示在picture_box1
			picture_box1->Image = image1;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// RGB Extraction & gray scale image

		// declaration of BitMap object for results
		Bitmap^ grayImage;
		Bitmap^ blueImage;
		Bitmap^ greenImage; 
		Bitmap^ redImage;
		grayImage	= gcnew Bitmap(image1->Width, image1->Height);
		blueImage	= gcnew Bitmap(image1->Width, image1->Height);
		greenImage	= gcnew Bitmap(image1->Width, image1->Height);
		redImage	= gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ grayImageData;
		Imaging::BitmapData^ blueImageData;
		Imaging::BitmapData^ greenImageData;
		Imaging::BitmapData^ redImageData;

		// Lock the image
		grayImageData	= grayImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		blueImageData	= blueImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		greenImageData	= greenImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		redImageData	= redImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		GrayResultPtr = grayImageData->Scan0;
		Gr = (Byte*)((Void*)GrayResultPtr);
		// Red
		RedResultPtr = redImageData->Scan0;
		R = (Byte*)((Void*)RedResultPtr);
		// Green
		GreenResultPtr = greenImageData->Scan0;
		G = (Byte*)((Void*)GreenResultPtr);
		// Blue
		BlueResultPtr = blueImageData->Scan0;
		B = (Byte*)((Void*)BlueResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// Gray Scale calculation, Gray = R*0.299 + G*0.587 + B*0.114
				// Using integer division for better performance, +50 for round
				int pixel = (p[0]*11 + p[1]*59 + p[2]*30 + 50) / 100;
				Gr[0] = (Byte)pixel;
				Gr[1] = (Byte)pixel;
				Gr[2] = (Byte)pixel;

				// Red Calculation
				pixel = (0 * 11 + 0 * 59 + p[2] * 30 + 50) / 100;
				R[0] = (Byte)pixel;
				R[1] = (Byte)pixel;
				R[2] = (Byte)pixel;

				// Green Calculation
				pixel = (0 * 11 + p[1] * 59 + 0 * 30 + 50) / 100;
				G[0] = (Byte)pixel;
				G[1] = (Byte)pixel;
				G[2] = (Byte)pixel;

				// Blue Calculation
				pixel = (p[0] * 11 + 0 * 59 + 0 * 30 + 50) / 100;
				B[0] = (Byte)pixel;
				B[1] = (Byte)pixel;
				B[2] = (Byte)pixel;

				// Move to next pixel
				Gr	+= 3;
				R	+= 3;
				G	+= 3;
				B	+= 3;
				p	+= 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		grayImage->UnlockBits(grayImageData);
		redImage->UnlockBits(redImageData);
		greenImage->UnlockBits(greenImageData);
		blueImage->UnlockBits(blueImageData);


		// show it on the pictureBox
		picture_box2->Image = grayImage;
	}
		   
	// Red Extraction
	private: System::Void buttonRed_Click(System::Object^ sender, System::EventArgs^ e) {
		// RGB Extraction & gray scale image

		// declaration of BitMap object for results
		Bitmap^ redImage;
		redImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ redImageData;

		// Lock the image
		redImageData = redImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		RedResultPtr = redImageData->Scan0;
		R = (Byte*)((Void*)RedResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// Gray Scale calculation, Gray = R*0.299 + G*0.587 + B*0.114
				// Using integer division for better performance, +50 for round
				// Red Calculation
				int pixel = (0 * 11 + 0 * 59 + p[2] * 30 + 50) / 100;
				R[0] = (Byte)pixel;
				R[1] = (Byte)pixel;
				R[2] = (Byte)pixel;

				// Move to next pixel
				R += 3;
				p += 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		redImage->UnlockBits(redImageData);

		// show it on the pictureBox
		picture_box2->Image = redImage;
	}
	private: System::Void buttonBlue_Click(System::Object^ sender, System::EventArgs^ e) {
		// RGB Extraction & gray scale image

		// declaration of BitMap object for results
		Bitmap^ blueImage;
		blueImage	= gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ blueImageData;

		// Lock the image
		blueImageData	= blueImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Blue
		BlueResultPtr = blueImageData->Scan0;
		B = (Byte*)((Void*)BlueResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// Gray Scale calculation, Gray = R*0.299 + G*0.587 + B*0.114
				// Using integer division for better performance, +50 for round
				// Blue Calculation
				int pixel = (p[0] * 11 + 0 * 59 + 0 * 30 + 50) / 100;
				B[0] = (Byte)pixel;
				B[1] = (Byte)pixel;
				B[2] = (Byte)pixel;

				// Move to next pixel
				B	+= 3;
				p	+= 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		blueImage->UnlockBits(blueImageData);


		// show it on the pictureBox
		picture_box2->Image = blueImage;
	}
	private: System::Void buttonGreen_Click(System::Object^ sender, System::EventArgs^ e) {
		// RGB Extraction & gray scale image

		// declaration of BitMap object for results
		Bitmap^ greenImage; 
		greenImage	= gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ greenImageData;

		// Lock the image
		greenImageData	= greenImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Green
		GreenResultPtr = greenImageData->Scan0;
		G = (Byte*)((Void*)GreenResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// Gray Scale calculation, Gray = R*0.299 + G*0.587 + B*0.114
				// Using integer division for better performance, +50 for round
				// Green Calculation
				int pixel = (0 * 11 + p[1] * 59 + 0 * 30 + 50) / 100;
				G[0] = (Byte)pixel;
				G[1] = (Byte)pixel;
				G[2] = (Byte)pixel;

				// Move to next pixel
				G	+= 3;
				p	+= 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		greenImage->UnlockBits(greenImageData);

		// show it on the pictureBox
		picture_box2->Image = greenImage;
	}
	private: System::Void buttonGray_Click(System::Object^ sender, System::EventArgs^ e) {
		// RGB Extraction & gray scale image

		// declaration of BitMap object for results
		Bitmap^ grayImage;
		grayImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ grayImageData;

		// Lock the image
		grayImageData = grayImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		GrayResultPtr = grayImageData->Scan0;
		Gr = (Byte*)((Void*)GrayResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// Gray Scale calculation, Gray = R*0.299 + G*0.587 + B*0.114
				// Using integer division for better performance, +50 for round
				int pixel = (p[0] * 11 + p[1] * 59 + p[2] * 30 + 50) / 100;
				Gr[0] = (Byte)pixel;
				Gr[1] = (Byte)pixel;
				Gr[2] = (Byte)pixel;

				// Move to next pixel
				Gr += 3;
				p += 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		grayImage->UnlockBits(grayImageData);

		// show it on the pictureBox
		picture_box2->Image = grayImage;
	}
	
	};
}
