#pragma once
#include <cmath>
#include <algorithm>

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
	private: System::Windows::Forms::Button^ buttonMean;
	private: System::Windows::Forms::Button^ buttonMedian;
	private: System::Windows::Forms::Button^ buttonHistogram;
	private: System::Windows::Forms::Button^ buttonThreshold;
	private: System::Windows::Forms::Button^ buttonSobelV;
	private: System::Windows::Forms::Button^ buttonSobelH;
	private: System::Windows::Forms::Button^ buttonSobelC;
	private: System::Windows::Forms::TextBox^ textBoxThresh;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->picture_box1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->picture_box2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonRed = (gcnew System::Windows::Forms::Button());
			this->buttonBlue = (gcnew System::Windows::Forms::Button());
			this->buttonGreen = (gcnew System::Windows::Forms::Button());
			this->buttonGray = (gcnew System::Windows::Forms::Button());
			this->buttonMean = (gcnew System::Windows::Forms::Button());
			this->buttonMedian = (gcnew System::Windows::Forms::Button());
			this->buttonHistogram = (gcnew System::Windows::Forms::Button());
			this->buttonThreshold = (gcnew System::Windows::Forms::Button());
			this->buttonSobelV = (gcnew System::Windows::Forms::Button());
			this->buttonSobelH = (gcnew System::Windows::Forms::Button());
			this->buttonSobelC = (gcnew System::Windows::Forms::Button());
			this->textBoxThresh = (gcnew System::Windows::Forms::TextBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			this->picture_box1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
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
			// picture_box2
			// 
			this->picture_box2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picture_box2->Location = System::Drawing::Point(544, 24);
			this->picture_box2->Name = L"picture_box2";
			this->picture_box2->Size = System::Drawing::Size(448, 448);
			this->picture_box2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture_box2->TabIndex = 3;
			this->picture_box2->TabStop = false;
			// 
			// buttonRed
			// 
			this->buttonRed->Location = System::Drawing::Point(32, 576);
			this->buttonRed->Name = L"buttonRed";
			this->buttonRed->Size = System::Drawing::Size(96, 32);
			this->buttonRed->TabIndex = 4;
			this->buttonRed->Text = L"Red Extraction";
			this->buttonRed->UseVisualStyleBackColor = true;
			this->buttonRed->Click += gcnew System::EventHandler(this, &MyForm::buttonRed_Click);
			// 
			// buttonBlue
			// 
			this->buttonBlue->Location = System::Drawing::Point(32, 640);
			this->buttonBlue->Name = L"buttonBlue";
			this->buttonBlue->Size = System::Drawing::Size(96, 32);
			this->buttonBlue->TabIndex = 5;
			this->buttonBlue->Text = L"Blue Extraction";
			this->buttonBlue->UseVisualStyleBackColor = true;
			this->buttonBlue->Click += gcnew System::EventHandler(this, &MyForm::buttonBlue_Click);
			// 
			// buttonGreen
			// 
			this->buttonGreen->Location = System::Drawing::Point(160, 576);
			this->buttonGreen->Name = L"buttonGreen";
			this->buttonGreen->Size = System::Drawing::Size(96, 32);
			this->buttonGreen->TabIndex = 6;
			this->buttonGreen->Text = L"Green Extraction";
			this->buttonGreen->UseVisualStyleBackColor = true;
			this->buttonGreen->Click += gcnew System::EventHandler(this, &MyForm::buttonGreen_Click);
			// 
			// buttonGray
			// 
			this->buttonGray->Location = System::Drawing::Point(160, 640);
			this->buttonGray->Name = L"buttonGray";
			this->buttonGray->Size = System::Drawing::Size(96, 32);
			this->buttonGray->TabIndex = 7;
			this->buttonGray->Text = L"Gray Scale";
			this->buttonGray->UseVisualStyleBackColor = true;
			this->buttonGray->Click += gcnew System::EventHandler(this, &MyForm::buttonGray_Click);
			// 
			// buttonMean
			// 
			this->buttonMean->Location = System::Drawing::Point(288, 576);
			this->buttonMean->Name = L"buttonMean";
			this->buttonMean->Size = System::Drawing::Size(96, 32);
			this->buttonMean->TabIndex = 8;
			this->buttonMean->Text = L"Mean Filter";
			this->buttonMean->UseVisualStyleBackColor = true;
			this->buttonMean->Click += gcnew System::EventHandler(this, &MyForm::buttonMean_Click);
			// 
			// buttonMedian
			// 
			this->buttonMedian->Location = System::Drawing::Point(288, 640);
			this->buttonMedian->Name = L"buttonMedian";
			this->buttonMedian->Size = System::Drawing::Size(96, 32);
			this->buttonMedian->TabIndex = 9;
			this->buttonMedian->Text = L"Median Filter";
			this->buttonMedian->UseVisualStyleBackColor = true;
			this->buttonMedian->Click += gcnew System::EventHandler(this, &MyForm::buttonMedian_Click);
			// 
			// buttonHistogram
			// 
			this->buttonHistogram->Location = System::Drawing::Point(416, 576);
			this->buttonHistogram->Name = L"buttonHistogram";
			this->buttonHistogram->Size = System::Drawing::Size(96, 32);
			this->buttonHistogram->TabIndex = 10;
			this->buttonHistogram->Text = L"Histogram Equalization";
			this->buttonHistogram->UseVisualStyleBackColor = true;
			this->buttonHistogram->Click += gcnew System::EventHandler(this, &MyForm::buttonHistogram_Click);
			// 
			// buttonThreshold
			// 
			this->buttonThreshold->Location = System::Drawing::Point(160, 704);
			this->buttonThreshold->Name = L"buttonThreshold";
			this->buttonThreshold->Size = System::Drawing::Size(96, 32);
			this->buttonThreshold->TabIndex = 11;
			this->buttonThreshold->Text = L"Threshold";
			this->buttonThreshold->UseVisualStyleBackColor = true;
			this->buttonThreshold->Click += gcnew System::EventHandler(this, &MyForm::buttonThreshold_Click);
			// 
			// buttonSobelV
			// 
			this->buttonSobelV->Location = System::Drawing::Point(544, 576);
			this->buttonSobelV->Name = L"buttonSobelV";
			this->buttonSobelV->Size = System::Drawing::Size(96, 32);
			this->buttonSobelV->TabIndex = 11;
			this->buttonSobelV->Text = L"Sobel Vertical";
			this->buttonSobelV->UseVisualStyleBackColor = true;
			this->buttonSobelV->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelV_Click);
			// 
			// buttonSobelH
			// 
			this->buttonSobelH->Location = System::Drawing::Point(544, 640);
			this->buttonSobelH->Name = L"buttonSobelH";
			this->buttonSobelH->Size = System::Drawing::Size(96, 32);
			this->buttonSobelH->TabIndex = 11;
			this->buttonSobelH->Text = L"Sobel Horizontal";
			this->buttonSobelH->UseVisualStyleBackColor = true;
			this->buttonSobelH->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelH_Click);
			// 
			// buttonSobelC
			// 
			this->buttonSobelC->Location = System::Drawing::Point(544, 704);
			this->buttonSobelC->Name = L"buttonSobelC";
			this->buttonSobelC->Size = System::Drawing::Size(96, 32);
			this->buttonSobelC->TabIndex = 11;
			this->buttonSobelC->Text = L"Sobel Combined";
			this->buttonSobelC->UseVisualStyleBackColor = true;
			this->buttonSobelC->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelC_Click);
			// 
			// textBoxThresh
			// 
			this->textBoxThresh->Location = System::Drawing::Point(32, 640);
			this->textBoxThresh->Name = L"textBoxThresh";
			this->textBoxThresh->Size = System::Drawing::Size(96, 22);
			this->textBoxThresh->TabIndex = 12;
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea2";
			this->chart2->ChartAreas->Add(chartArea2);
			this->chart2->Location = System::Drawing::Point(713, 657);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea2";
			series2->Name = L"Series2";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(279, 101);
			this->chart2->TabIndex = 14;
			this->chart2->Text = L"chart2";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(713, 551);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(279, 101);
			this->chart1->TabIndex = 15;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->picture_box1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->picture_box2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonRed);
			this->Controls->Add(this->buttonGreen);
			this->Controls->Add(this->buttonBlue);
			this->Controls->Add(this->buttonGray);
			this->Controls->Add(this->buttonMean);
			this->Controls->Add(this->buttonMedian);
			this->Controls->Add(this->buttonHistogram);
			this->Controls->Add(this->buttonThreshold);
			this->Controls->Add(this->buttonSobelV);
			this->Controls->Add(this->buttonSobelH);
			this->Controls->Add(this->buttonSobelC);
			this->Controls->Add(this->textBoxThresh);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Bitmap object for the picture you opened宣告Bitmap 儲存開啟的圖
		Bitmap^ image1;

		// BitmapData object data for pixel
		Imaging::BitmapData^ ImageData1;

		// Image area
		Rectangle rect;

		// int pointer for calculation
		IntPtr ptr, GrayResultPtr, RedResultPtr, GreenResultPtr, BlueResultPtr;
		IntPtr meanResultPtr, medianResultPtr, histResultPtr, threshResultPtr;
		IntPtr sobelVResultPtr, sobelHResultPtr, sobelCResultPtr;

		// Byte pointer
		Byte* p;
		Byte* Gr;
		Byte* G;
		Byte* R;
		Byte* B;
		Byte* mean;
		Byte* median;
		Byte* sobelV;
		Byte* sobelH;
		Byte* sobelC;

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
	private: System::Void buttonMean_Click(System::Object^ sender, System::EventArgs^ e) {
		// Mean Filter

		// declaration of BitMap object for results
		Bitmap^ meanImage;
		meanImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ meanImageData;

		// Lock the image
		meanImageData = meanImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		meanResultPtr = meanImageData->Scan0;
		mean = (Byte*)((Void*)meanResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel(without_boundary)
		for (int y = 0; y < image1->Height+1; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// boundary cases
				if(y == 0) {
					int b_idx = 3*x;
					int g_idx = 3*x + 1;
					int r_idx = 3*x + 2;
					mean[b_idx] = p[b_idx];
					mean[g_idx] = p[g_idx];
					mean[r_idx] = p[r_idx];
					continue;
				}
				else if(y == image1->Height || x == 0 || x == image1->Width-1) {
					int b_idx = 3*x + 3 * image1->Width * (y-1);
					int g_idx = 3*x + 3 * image1->Width * (y-1) + 1;
					int r_idx = 3*x + 3 * image1->Width * (y-1) + 2;
					mean[b_idx] = p[b_idx];
					mean[g_idx] = p[g_idx];
					mean[r_idx] = p[r_idx];
					continue;
				}
				
				// index setup
				int top_left_idx 	= 3*(x-1) + 3 * image1->Width * (y-1);
				int top_idx 		= 3*(x)   + 3 * image1->Width * (y-1);
				int top_right_idx 	= 3*(x+1) + 3 * image1->Width * (y-1);
				int left_idx 		= 3*(x-1) + 3 * image1->Width * (y);
				int mid_idx 		= 3*(x)   + 3 * image1->Width * (y);
				int right_idx 		= 3*(x+1) + 3 * image1->Width * (y);
				int bot_left_idx 	= 3*(x-1) + 3 * image1->Width * (y+1);
				int bot_idx 		= 3*(x)   + 3 * image1->Width * (y+1);
				int bot_right_idx 	= 3*(x+1) + 3 * image1->Width * (y+1);
				
				// mean_filter
				int b_mean = (p[top_left_idx] + p[top_idx] + p[top_right_idx]
					+ p[left_idx] + p[mid_idx] + p[right_idx]
					+ p[bot_left_idx] + p[bot_idx] + p[bot_right_idx]) / 9;
				int g_mean = (p[top_left_idx + 1] + p[top_idx + 1] + p[top_right_idx + 1]
						+ p[left_idx + 1] + p[mid_idx + 1] + p[right_idx + 1]
						+ p[bot_left_idx + 1] + p[bot_idx + 1] + p[bot_right_idx + 1]) / 9;
				int r_mean = (p[top_left_idx + 2] + p[top_idx + 2] + p[top_right_idx + 2]
						+ p[left_idx + 2] + p[mid_idx + 2] + p[right_idx + 2]
						+ p[bot_left_idx + 2] + p[bot_idx + 2] + p[bot_right_idx + 2]) / 9;
				
				// put averaged value into the result
				mean[mid_idx] = (Byte)b_mean;
				mean[mid_idx+1] = (Byte)g_mean;
				mean[mid_idx+2] = (Byte)r_mean;

			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		meanImage->UnlockBits(meanImageData);

		// show it on the pictureBox
		picture_box2->Image = meanImage;
	}
	private: System::Void buttonMedian_Click(System::Object^ sender, System::EventArgs^ e) {
		// Median Filter

		// declaration of BitMap object for results
		Bitmap^ medianImage;
		medianImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ medianImageData;

		// Lock the image
		medianImageData = medianImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		medianResultPtr = medianImageData->Scan0;
		median = (Byte*)((Void*)medianResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel(without_boundary)
		for (int y = 0; y < image1->Height+1; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// boundary cases
				if(y == 0) {
					int b_idx = 3*x;
					int g_idx = 3*x + 1;
					int r_idx = 3*x + 2;
					median[b_idx] = p[b_idx];
					median[g_idx] = p[g_idx];
					median[r_idx] = p[r_idx];
					continue;
				}
				else if(y == image1->Height || x == 0 || x == image1->Width-1) {
					int b_idx = 3*x + 3 * image1->Width * (y-1);
					int g_idx = 3*x + 3 * image1->Width * (y-1) + 1;
					int r_idx = 3*x + 3 * image1->Width * (y-1) + 2;
					median[b_idx] = p[b_idx];
					median[g_idx] = p[g_idx];
					median[r_idx] = p[r_idx];
					continue;
				}
				
				// index setup
				int top_left_idx 	= 3*(x-1) + 3 * image1->Width * (y-1);
				int top_idx 		= 3*(x)   + 3 * image1->Width * (y-1);
				int top_right_idx 	= 3*(x+1) + 3 * image1->Width * (y-1);
				int left_idx 		= 3*(x-1) + 3 * image1->Width * (y);
				int mid_idx 		= 3*(x)   + 3 * image1->Width * (y);
				int right_idx 		= 3*(x+1) + 3 * image1->Width * (y);
				int bot_left_idx 	= 3*(x-1) + 3 * image1->Width * (y+1);
				int bot_idx 		= 3*(x)   + 3 * image1->Width * (y+1);
				int bot_right_idx 	= 3*(x+1) + 3 * image1->Width * (y+1);
				
				// array setup
				int b_sorted_array[9] = { p[top_left_idx], p[top_idx], p[top_right_idx],
										p[left_idx], p[mid_idx], p[right_idx],
										p[bot_left_idx], p[bot_idx], p[bot_right_idx] };
				int g_sorted_array[9] = { p[top_left_idx + 1], p[top_idx + 1], p[top_right_idx + 1],
											p[left_idx + 1], p[mid_idx + 1], p[right_idx + 1],
											p[bot_left_idx + 1], p[bot_idx + 1], p[bot_right_idx + 1] };
				int r_sorted_array[9] = { p[top_left_idx + 2], p[top_idx + 2], p[top_right_idx + 2],
											p[left_idx + 2], p[mid_idx + 2], p[right_idx + 2],
											p[bot_left_idx + 2], p[bot_idx + 2], p[bot_right_idx + 2] };
				
				// sort array
				std::sort(b_sorted_array, b_sorted_array+9);
				std::sort(g_sorted_array, g_sorted_array+9);
				std::sort(r_sorted_array, r_sorted_array+9);
				
				// median_filter
				// put median into the result
				median[mid_idx] = (Byte)b_sorted_array[5];
				median[mid_idx+1] = (Byte)g_sorted_array[5];
				median[mid_idx+2] = (Byte)r_sorted_array[5];

			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		medianImage->UnlockBits(medianImageData);

		// show it on the pictureBox
		picture_box2->Image = medianImage;
	}
	private: System::Void buttonHistogram_Click(System::Object^ sender, System::EventArgs^ e) {
		// Histogram Equalization

		// declaration of BitMap object for results
		Bitmap^ histImage;
		histImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ histImageData;

		// Lock the image
		histImageData = histImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// hist, set int ptr to the front of the image
		histResultPtr = histImageData->Scan0;
		Gr = (Byte*)((Void*)histResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		int histogram[256];
		int histogram_2[256];
		for (int i = 0; i < 256; i++) {
			histogram[i] = 0;
			histogram_2[i] = 0;
		}

		// process all pixel
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// bin calculation
				histogram[(int)p[0]]++;
				p += 3;
			}
		}
		// Draw histogram for original image
		chart1->Series["Series1"]->Points->Clear();
		for(int i = 0; i < 256; i++)
			chart1->Series["Series1"]->Points->AddXY(i, histogram[i]);

		// Find first non-zero bin
		int i = 0;
		while (!histogram[i]) ++i;

		int sum = 0;
		int lut[256];
		float scale = (255 - 1.f) / (image1->Height * image1->Width - histogram[i]);
		i++;
		for(int j = 0; j < 256; ++j)
			lut[j] = 0;
		for (; i < 256; ++i) {
			sum += histogram[i];
			// the value is saturated in range [0, max_val]
			lut[i] = std::max(0, std::min(int(std::round(sum * scale)), 255));
		}

		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				int pixel = 0;
				pixel = lut[p[0]];
				histogram_2[pixel]++;

				Gr[0] = (Byte)pixel;
				Gr[1] = (Byte)pixel;
				Gr[2] = (Byte)pixel;

				Gr += 3;
				p += 3;
			}
		}
		// Draw histogram for original image
		chart2->Series["Series2"]->Points->Clear();
		for (int i = 0; i < 256; i++)
			chart2->Series["Series2"]->Points->AddXY(i, histogram_2[i]);

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		histImage->UnlockBits(histImageData);

		// show it on the pictureBox
		picture_box2->Image = histImage;
	}
	private: System::Void buttonThreshold_Click(System::Object^ sender, System::EventArgs^ e) {
		// Threshold Filter 
		
		int threshold = Convert::ToInt32(textBoxThresh->Text);
		//double threshold = 128;

		// declaration of BitMap object for results
		Bitmap^ threshImage;
		threshImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ threshImageData;

		// Lock the image
		threshImageData = threshImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// thresh, set int ptr to the front of the image
		threshResultPtr = threshImageData->Scan0;
		Gr = (Byte*)((Void*)threshResultPtr);

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
				int pixel;
				// Threshold filter
				if (p[0] > threshold || p[1] > threshold || p[2] > threshold) {
					Gr[0] = p[0];
					Gr[1] = p[1];
					Gr[2] = p[2];
				}
				else {
					pixel = 0;
					Gr[0] = (Byte)pixel;
					Gr[1] = (Byte)pixel;
					Gr[2] = (Byte)pixel;
				}
					

				// Move to next pixel
				Gr += 3;
				p += 3;
			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		threshImage->UnlockBits(threshImageData);

		// show it on the pictureBox
		picture_box2->Image = threshImage;
	}

	private: System::Void buttonSobelV_Click(System::Object^ sender, System::EventArgs^ e) {
		// Mean Filter

		// declaration of BitMap object for results
		Bitmap^ sobelVImage;
		sobelVImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ sobelVImageData;

		// Lock the image
		sobelVImageData = sobelVImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		sobelVResultPtr = sobelVImageData->Scan0;
		sobelV = (Byte*)((Void*)sobelVResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel(without_boundary)
		for (int y = 0; y < image1->Height + 1; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// boundary cases
				if (y == 0) {
					int b_idx = 3 * x;
					int g_idx = 3 * x + 1;
					int r_idx = 3 * x + 2;
					sobelV[b_idx] = p[b_idx];
					sobelV[g_idx] = p[g_idx];
					sobelV[r_idx] = p[r_idx];
					continue;
				}
				else if (y == image1->Height || x == 0 || x == image1->Width - 1) {
					int b_idx = 3 * x + 3 * image1->Width * (y - 1);
					int g_idx = 3 * x + 3 * image1->Width * (y - 1) + 1;
					int r_idx = 3 * x + 3 * image1->Width * (y - 1) + 2;
					sobelV[b_idx] = p[b_idx];
					sobelV[g_idx] = p[g_idx];
					sobelV[r_idx] = p[r_idx];
					continue;
				}

				// index setup
				int top_left_idx = 3 * (x - 1) + 3 * image1->Width * (y - 1);
				int top_idx = 3 * (x)+3 * image1->Width * (y - 1);
				int top_right_idx = 3 * (x + 1) + 3 * image1->Width * (y - 1);
				int left_idx = 3 * (x - 1) + 3 * image1->Width * (y);
				int mid_idx = 3 * (x)+3 * image1->Width * (y);
				int right_idx = 3 * (x + 1) + 3 * image1->Width * (y);
				int bot_left_idx = 3 * (x - 1) + 3 * image1->Width * (y + 1);
				int bot_idx = 3 * (x)+3 * image1->Width * (y + 1);
				int bot_right_idx = 3 * (x + 1) + 3 * image1->Width * (y + 1);

				// Sobel Vertical
				int value = (p[top_left_idx] + 2 * p[top_idx] + p[top_right_idx] - p[bot_left_idx] - 2 * p[bot_idx] - p[bot_right_idx]);
				if (value < 0)
					value = 0;
				else if (value > 255)
					value = 255;

				int b_sobelV = value;
				int g_sobelV = value;
				int r_sobelV = value;


				// put averaged value into the result
				sobelV[mid_idx] = (Byte)b_sobelV;
				sobelV[mid_idx + 1] = (Byte)g_sobelV;
				sobelV[mid_idx + 2] = (Byte)r_sobelV;

			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		sobelVImage->UnlockBits(sobelVImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelVImage;
	}

	private: System::Void buttonSobelH_Click(System::Object^ sender, System::EventArgs^ e) {
		// Mean Filter

		// declaration of BitMap object for results
		Bitmap^ sobelHImage;
		sobelHImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ sobelHImageData;

		// Lock the image
		sobelHImageData = sobelHImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		sobelHResultPtr = sobelHImageData->Scan0;
		sobelH = (Byte*)((Void*)sobelHResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel(without_boundary)
		for (int y = 0; y < image1->Height + 1; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// boundary cases
				if (y == 0) {
					int b_idx = 3 * x;
					int g_idx = 3 * x + 1;
					int r_idx = 3 * x + 2;
					sobelH[b_idx] = p[b_idx];
					sobelH[g_idx] = p[g_idx];
					sobelH[r_idx] = p[r_idx];
					continue;
				}
				else if (y == image1->Height || x == 0 || x == image1->Width - 1) {
					int b_idx = 3 * x + 3 * image1->Width * (y - 1);
					int g_idx = 3 * x + 3 * image1->Width * (y - 1) + 1;
					int r_idx = 3 * x + 3 * image1->Width * (y - 1) + 2;
					sobelH[b_idx] = p[b_idx];
					sobelH[g_idx] = p[g_idx];
					sobelH[r_idx] = p[r_idx];
					continue;
				}

				// index setup
				int top_left_idx = 3 * (x - 1) + 3 * image1->Width * (y - 1);
				int top_idx = 3 * (x)+3 * image1->Width * (y - 1);
				int top_right_idx = 3 * (x + 1) + 3 * image1->Width * (y - 1);
				int left_idx = 3 * (x - 1) + 3 * image1->Width * (y);
				int mid_idx = 3 * (x)+3 * image1->Width * (y);
				int right_idx = 3 * (x + 1) + 3 * image1->Width * (y);
				int bot_left_idx = 3 * (x - 1) + 3 * image1->Width * (y + 1);
				int bot_idx = 3 * (x)+3 * image1->Width * (y + 1);
				int bot_right_idx = 3 * (x + 1) + 3 * image1->Width * (y + 1);

				// Sobel Horizontal
				int value = (p[top_left_idx] - p[top_right_idx]+ 2 * p[left_idx] - 2 * p[right_idx] + 2 * p[bot_left_idx] - p[bot_right_idx]);
				if (value < 0)
					value = 0;
				else if (value > 255)
					value = 255;

				int b_sobelH = value;
				int g_sobelH = value;
				int r_sobelH = value;

				// put averaged value into the result
				sobelH[mid_idx] = (Byte)b_sobelH;
				sobelH[mid_idx + 1] = (Byte)g_sobelH;
				sobelH[mid_idx + 2] = (Byte)r_sobelH;

			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		sobelHImage->UnlockBits(sobelHImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelHImage;
	}

	private: System::Void buttonSobelC_Click(System::Object^ sender, System::EventArgs^ e) {
		// Mean Filter

		// declaration of BitMap object for results
		Bitmap^ sobelCImage;
		sobelCImage = gcnew Bitmap(image1->Width, image1->Height);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ sobelCImageData;

		// Lock the image
		sobelCImageData = sobelCImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		sobelCResultPtr = sobelCImageData->Scan0;
		sobelC = (Byte*)((Void*)sobelCResultPtr);

		// Lock the original image
		ImageData1 = image1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel(without_boundary)
		for (int y = 0; y < image1->Height + 1; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// boundary cases
				if (y == 0) {
					int b_idx = 3 * x;
					int g_idx = 3 * x + 1;
					int r_idx = 3 * x + 2;
					sobelC[b_idx] = p[b_idx];
					sobelC[g_idx] = p[g_idx];
					sobelC[r_idx] = p[r_idx];
					continue;
				}
				else if (y == image1->Height || x == 0 || x == image1->Width - 1) {
					int b_idx = 3 * x + 3 * image1->Width * (y - 1);
					int g_idx = 3 * x + 3 * image1->Width * (y - 1) + 1;
					int r_idx = 3 * x + 3 * image1->Width * (y - 1) + 2;
					sobelC[b_idx] = p[b_idx];
					sobelC[g_idx] = p[g_idx];
					sobelC[r_idx] = p[r_idx];
					continue;
				}

				// index setup
				int top_left_idx = 3 * (x - 1) + 3 * image1->Width * (y - 1);
				int top_idx = 3 * (x)+3 * image1->Width * (y - 1);
				int top_right_idx = 3 * (x + 1) + 3 * image1->Width * (y - 1);
				int left_idx = 3 * (x - 1) + 3 * image1->Width * (y);
				int mid_idx = 3 * (x)+3 * image1->Width * (y);
				int right_idx = 3 * (x + 1) + 3 * image1->Width * (y);
				int bot_left_idx = 3 * (x - 1) + 3 * image1->Width * (y + 1);
				int bot_idx = 3 * (x)+3 * image1->Width * (y + 1);
				int bot_right_idx = 3 * (x + 1) + 3 * image1->Width * (y + 1);

				// Sobel Vertical
				int b_sobelC = (p[top_left_idx] + 2 * p[top_idx] + p[top_right_idx]
					- p[bot_left_idx] - 2 * p[bot_idx] - p[bot_right_idx]);
				int g_sobelC = (p[top_left_idx] + 2 * p[top_idx] + p[top_right_idx]
					- p[bot_left_idx] - 2 * p[bot_idx] - p[bot_right_idx]);
				int r_sobelC = (p[top_left_idx] + 2 * p[top_idx] + p[top_right_idx]
					- p[bot_left_idx] - 2 * p[bot_idx] - p[bot_right_idx]);

				// put averaged value into the result
				sobelC[mid_idx] = (Byte)b_sobelC;
				sobelC[mid_idx + 1] = (Byte)g_sobelC;
				sobelC[mid_idx + 2] = (Byte)r_sobelC;

			}
		}

		// Unlock pixel
		image1->UnlockBits(ImageData1);
		sobelCImage->UnlockBits(sobelCImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelCImage;
	}
};
}
