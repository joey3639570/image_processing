#pragma once
#include <stack>
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
	private: System::Windows::Forms::Button^ buttonConnected;
	private: System::Windows::Forms::Button^ buttonOverlap;
	private: System::Windows::Forms::Button^ buttonRegistration;
	private: System::Windows::Forms::TextBox^ textBoxThresh;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: array< Bitmap^ >^ image_list = gcnew array< Bitmap^ >(30);
	private: array<Point^ >^ point_list = gcnew array<Point^ >(4);
	private: int image_list_idx = 0;
	private: int point_list_idx = 0;
	private: int point_list_2_idx = 4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

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
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
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
			this->buttonOverlap = (gcnew System::Windows::Forms::Button());
			this->buttonConnected = (gcnew System::Windows::Forms::Button());
			this->buttonRegistration = (gcnew System::Windows::Forms::Button());
			this->textBoxThresh = (gcnew System::Windows::Forms::TextBox());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(192, 484);
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
			this->button2->Location = System::Drawing::Point(445, 484);
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
			this->buttonRed->Location = System::Drawing::Point(7, 27);
			this->buttonRed->Name = L"buttonRed";
			this->buttonRed->Size = System::Drawing::Size(96, 32);
			this->buttonRed->TabIndex = 4;
			this->buttonRed->Text = L"Red Extraction";
			this->buttonRed->UseVisualStyleBackColor = true;
			this->buttonRed->Click += gcnew System::EventHandler(this, &MyForm::buttonRed_Click);
			// 
			// buttonBlue
			// 
			this->buttonBlue->Location = System::Drawing::Point(7, 91);
			this->buttonBlue->Name = L"buttonBlue";
			this->buttonBlue->Size = System::Drawing::Size(96, 32);
			this->buttonBlue->TabIndex = 5;
			this->buttonBlue->Text = L"Blue Extraction";
			this->buttonBlue->UseVisualStyleBackColor = true;
			this->buttonBlue->Click += gcnew System::EventHandler(this, &MyForm::buttonBlue_Click);
			// 
			// buttonGreen
			// 
			this->buttonGreen->Location = System::Drawing::Point(135, 27);
			this->buttonGreen->Name = L"buttonGreen";
			this->buttonGreen->Size = System::Drawing::Size(96, 32);
			this->buttonGreen->TabIndex = 6;
			this->buttonGreen->Text = L"Green Extraction";
			this->buttonGreen->UseVisualStyleBackColor = true;
			this->buttonGreen->Click += gcnew System::EventHandler(this, &MyForm::buttonGreen_Click);
			// 
			// buttonGray
			// 
			this->buttonGray->Location = System::Drawing::Point(135, 91);
			this->buttonGray->Name = L"buttonGray";
			this->buttonGray->Size = System::Drawing::Size(96, 32);
			this->buttonGray->TabIndex = 7;
			this->buttonGray->Text = L"Gray Scale";
			this->buttonGray->UseVisualStyleBackColor = true;
			this->buttonGray->Click += gcnew System::EventHandler(this, &MyForm::buttonGray_Click);
			// 
			// buttonMean
			// 
			this->buttonMean->Location = System::Drawing::Point(6, 26);
			this->buttonMean->Name = L"buttonMean";
			this->buttonMean->Size = System::Drawing::Size(96, 32);
			this->buttonMean->TabIndex = 8;
			this->buttonMean->Text = L"Mean Filter";
			this->buttonMean->UseVisualStyleBackColor = true;
			this->buttonMean->Click += gcnew System::EventHandler(this, &MyForm::buttonMean_Click);
			// 
			// buttonMedian
			// 
			this->buttonMedian->Location = System::Drawing::Point(6, 90);
			this->buttonMedian->Name = L"buttonMedian";
			this->buttonMedian->Size = System::Drawing::Size(96, 32);
			this->buttonMedian->TabIndex = 9;
			this->buttonMedian->Text = L"Median Filter";
			this->buttonMedian->UseVisualStyleBackColor = true;
			this->buttonMedian->Click += gcnew System::EventHandler(this, &MyForm::buttonMedian_Click);
			// 
			// buttonHistogram
			// 
			this->buttonHistogram->Location = System::Drawing::Point(32, 704);
			this->buttonHistogram->Name = L"buttonHistogram";
			this->buttonHistogram->Size = System::Drawing::Size(96, 32);
			this->buttonHistogram->TabIndex = 10;
			this->buttonHistogram->Text = L"Histogram Equalization";
			this->buttonHistogram->UseVisualStyleBackColor = true;
			this->buttonHistogram->Click += gcnew System::EventHandler(this, &MyForm::buttonHistogram_Click);
			// 
			// buttonThreshold
			// 
			this->buttonThreshold->Location = System::Drawing::Point(5, 14);
			this->buttonThreshold->Name = L"buttonThreshold";
			this->buttonThreshold->Size = System::Drawing::Size(96, 32);
			this->buttonThreshold->TabIndex = 11;
			this->buttonThreshold->Text = L"Threshold";
			this->buttonThreshold->UseVisualStyleBackColor = true;
			this->buttonThreshold->Click += gcnew System::EventHandler(this, &MyForm::buttonThreshold_Click);
			// 
			// buttonSobelV
			// 
			this->buttonSobelV->Location = System::Drawing::Point(11, 27);
			this->buttonSobelV->Name = L"buttonSobelV";
			this->buttonSobelV->Size = System::Drawing::Size(96, 32);
			this->buttonSobelV->TabIndex = 11;
			this->buttonSobelV->Text = L"Sobel Vertical";
			this->buttonSobelV->UseVisualStyleBackColor = true;
			this->buttonSobelV->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelV_Click);
			// 
			// buttonSobelH
			// 
			this->buttonSobelH->Location = System::Drawing::Point(11, 91);
			this->buttonSobelH->Name = L"buttonSobelH";
			this->buttonSobelH->Size = System::Drawing::Size(96, 32);
			this->buttonSobelH->TabIndex = 11;
			this->buttonSobelH->Text = L"Sobel Horizontal";
			this->buttonSobelH->UseVisualStyleBackColor = true;
			this->buttonSobelH->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelH_Click);
			// 
			// buttonSobelC
			// 
			this->buttonSobelC->Location = System::Drawing::Point(139, 27);
			this->buttonSobelC->Name = L"buttonSobelC";
			this->buttonSobelC->Size = System::Drawing::Size(96, 32);
			this->buttonSobelC->TabIndex = 11;
			this->buttonSobelC->Text = L"Sobel Combined";
			this->buttonSobelC->UseVisualStyleBackColor = true;
			this->buttonSobelC->Click += gcnew System::EventHandler(this, &MyForm::buttonSobelC_Click);
			// 
			// buttonOverlap
			// 
			this->buttonOverlap->Location = System::Drawing::Point(139, 91);
			this->buttonOverlap->Name = L"buttonOverlap";
			this->buttonOverlap->Size = System::Drawing::Size(96, 32);
			this->buttonOverlap->TabIndex = 11;
			this->buttonOverlap->Text = L"Sobel Overlap";
			this->buttonOverlap->UseVisualStyleBackColor = true;
			this->buttonOverlap->Click += gcnew System::EventHandler(this, &MyForm::buttonOverlap_Click);
			// 
			// buttonConnected
			// 
			this->buttonConnected->Location = System::Drawing::Point(416, 704);
			this->buttonConnected->Name = L"buttonConnected";
			this->buttonConnected->Size = System::Drawing::Size(96, 32);
			this->buttonConnected->TabIndex = 11;
			this->buttonConnected->Text = L"Connected Components";
			this->buttonConnected->UseVisualStyleBackColor = true;
			this->buttonConnected->Click += gcnew System::EventHandler(this, &MyForm::buttonConnected_Click);
			// 
			// buttonRegistration
			// 
			this->buttonRegistration->Location = System::Drawing::Point(544, 704);
			this->buttonRegistration->Name = L"buttonRegistration";
			this->buttonRegistration->Size = System::Drawing::Size(96, 32);
			this->buttonRegistration->TabIndex = 11;
			this->buttonRegistration->Text = L"Image Registration";
			this->buttonRegistration->UseVisualStyleBackColor = true;
			this->buttonRegistration->Click += gcnew System::EventHandler(this, &MyForm::buttonRegistration_Click);
			// 
			// textBoxThresh
			// 
			this->textBoxThresh->Location = System::Drawing::Point(133, 21);
			this->textBoxThresh->Name = L"textBoxThresh";
			this->textBoxThresh->Size = System::Drawing::Size(96, 22);
			this->textBoxThresh->TabIndex = 12;
			// 
			// chart2
			// 
			chartArea1->Name = L"ChartArea2";
			this->chart2->ChartAreas->Add(chartArea1);
			this->chart2->Location = System::Drawing::Point(689, 655);
			this->chart2->Name = L"chart2";
			series1->ChartArea = L"ChartArea2";
			series1->Name = L"Series2";
			this->chart2->Series->Add(series1);
			this->chart2->Size = System::Drawing::Size(279, 101);
			this->chart2->TabIndex = 14;
			this->chart2->Text = L"chart2";
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Location = System::Drawing::Point(689, 538);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(279, 101);
			this->chart1->TabIndex = 15;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 479);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 12);
			this->label1->TabIndex = 16;
			this->label1->Text = L"PixelFormat";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonSobelV);
			this->groupBox1->Controls->Add(this->buttonSobelH);
			this->groupBox1->Controls->Add(this->buttonSobelC);
			this->groupBox1->Controls->Add(this->buttonOverlap);
			this->groupBox1->Location = System::Drawing::Point(405, 550);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(252, 134);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Question5,6";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonMean);
			this->groupBox2->Controls->Add(this->buttonMedian);
			this->groupBox2->Location = System::Drawing::Point(282, 551);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(112, 133);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Question2";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->buttonRed);
			this->groupBox3->Controls->Add(this->buttonGreen);
			this->groupBox3->Controls->Add(this->buttonBlue);
			this->groupBox3->Controls->Add(this->buttonGray);
			this->groupBox3->Location = System::Drawing::Point(25, 551);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(242, 133);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Question3";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->buttonThreshold);
			this->groupBox4->Controls->Add(this->textBoxThresh);
			this->groupBox4->Location = System::Drawing::Point(155, 690);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(238, 56);
			this->groupBox4->TabIndex = 20;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Question4";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 690);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 12);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Question3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(416, 690);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 12);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Question7";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(544, 690);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 12);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Question8";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(689, 524);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 12);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Histogram Before";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(689, 642);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 12);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Histogram After";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(703, 484);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(128, 32);
			this->button3->TabIndex = 26;
			this->button3->Text = L"開啟圖片";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(838, 479);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 12);
			this->label7->TabIndex = 27;
			this->label7->Text = L"Scaling factor:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(838, 495);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(76, 12);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Rotation angle:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(838, 511);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 12);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Intensity difference:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->picture_box1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->picture_box2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonHistogram);
			this->Controls->Add(this->buttonConnected);
			this->Controls->Add(this->buttonRegistration);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture_box2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Bitmap object for the picture you opened宣告Bitmap 儲存開啟的圖
		Bitmap^ image1;

		// Bitmap for registration
		Bitmap^ image2;

		// BitmapData object data for pixel
		Imaging::BitmapData^ ImageData1;

		// Image area
		Rectangle rect;

		// int pointer for calculation
		IntPtr ptr, GrayResultPtr, RedResultPtr, GreenResultPtr, BlueResultPtr;
		IntPtr meanResultPtr, medianResultPtr, histResultPtr, threshResultPtr;
		IntPtr sobelVResultPtr, sobelHResultPtr, sobelCResultPtr;
		IntPtr connectedPtr, OverlapPtr, RegistrationResultPtr;

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
		Byte* connected;
		Byte* Overlap;
		Byte* Registration;

		Point coordinates;

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
			label1->Text = String::Format("Pixel format: {0}", image1->PixelFormat);
			image_list[0] = image1;
			image_list_idx = 1;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (image_list_idx > 1)
			image_list_idx -= 1;
		picture_box2->Image = image_list[image_list_idx-1];
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
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
		topImage->UnlockBits(ImageData1);
		redImage->UnlockBits(redImageData);

		// show it on the pictureBox
		picture_box2->Image = redImage;
		image_list[image_list_idx++] = redImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
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
		topImage->UnlockBits(ImageData1);
		blueImage->UnlockBits(blueImageData);


		// show it on the pictureBox
		picture_box2->Image = blueImage;
		image_list[image_list_idx++] = blueImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
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
		topImage->UnlockBits(ImageData1);
		greenImage->UnlockBits(greenImageData);

		// show it on the pictureBox
		picture_box2->Image = greenImage;
		image_list[image_list_idx++] = greenImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
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
		topImage->UnlockBits(ImageData1);
		grayImage->UnlockBits(grayImageData);

		// show it on the pictureBox
		picture_box2->Image = grayImage;
		image_list[image_list_idx++] = grayImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);
		
		// Byte ptr array
		Byte* r[9];

		// Array for pixel value and pixel index
		int Array_r[9] = { 0 };
		int Array_g[9] = { 0 };
		int Array_b[9] = { 0 };

		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// not dealing with boundary cases
				if (y > 0 && x > 0 && y < image1->Height - 1 && x < image1->Width - 1)
				{
					int Masksize = 0;
					//save pixel value for calculating
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -3; j <= 3; j += 3)
						{
							// point the ptr to the target
							r[Masksize] = (Byte*)(Void*)p + i * image1->Width * 3 + j;
							// save pixel
							Array_b[Masksize] = r[Masksize][0];
							Array_g[Masksize] = r[Masksize][1];
							Array_r[Masksize] = r[Masksize][2];
							Masksize++;
						}
					}
					int value_b = (Array_b[0] + Array_b[1] + Array_b[2] + Array_b[3] + Array_b[4] + Array_b[5] + Array_b[6] + Array_b[7] + Array_b[8]) / 9;
					int value_g = (Array_g[0] + Array_g[1] + Array_g[2] + Array_g[3] + Array_g[4] + Array_g[5] + Array_g[6] + Array_g[7] + Array_g[8]) / 9;
					int value_r = (Array_r[0] + Array_r[1] + Array_r[2] + Array_r[3] + Array_r[4] + Array_r[5] + Array_r[6] + Array_r[7] + Array_r[8]) / 9;

					mean[0] = (Byte)value_b;
					mean[1] = (Byte)value_g;
					mean[2] = (Byte)value_r;
				}
				else
				{
					mean[0] = p[0];
					mean[1] = p[1];
					mean[2] = p[2];
				}
				mean += 3;
				p += 3;
			}
		}

		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		meanImage->UnlockBits(meanImageData);

		// show it on the pictureBox
		picture_box2->Image = meanImage;
		image_list[image_list_idx++] = meanImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// Byte ptr array
		Byte* r[9];

		// Array for pixel value and pixel index
		int Array_r[9] = { 0 };
		int Array_g[9] = { 0 };
		int Array_b[9] = { 0 };

		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				// not dealing with boundary cases
				if (y > 0 && x > 0 && y < image1->Height - 1 && x < image1->Width - 1)
				{
					int Masksize = 0;
					//save pixel value for calculating
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -3; j <= 3; j += 3)
						{
							// point the ptr to the target
							r[Masksize] = (Byte*)(Void*)p + i * image1->Width * 3 + j;
							// save pixel
							Array_b[Masksize] = r[Masksize][0];
							Array_g[Masksize] = r[Masksize][1];
							Array_r[Masksize] = r[Masksize][2];
							Masksize++;
						}
					}

					// sort array
					std::sort(Array_b, Array_b + 9);
					std::sort(Array_g, Array_g + 9);
					std::sort(Array_r, Array_r + 9);

					median[0] = (Byte)Array_b[4];
					median[1] = (Byte)Array_g[4];
					median[2] = (Byte)Array_r[4];
				}
				else
				{
					median[0] = p[0];
					median[1] = p[1];
					median[2] = p[2];
				}
				median += 3;
				p += 3;
			}
		}

		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		medianImage->UnlockBits(medianImageData);

		// show it on the pictureBox
		picture_box2->Image = medianImage;
		image_list[image_list_idx++] = medianImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
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
		topImage->UnlockBits(ImageData1);
		histImage->UnlockBits(histImageData);

		// show it on the pictureBox
		picture_box2->Image = histImage;
		image_list[image_list_idx++] = histImage;
	}
	private: System::Void buttonThreshold_Click(System::Object^ sender, System::EventArgs^ e) {
		// Threshold Filter 
		
		int threshold = Convert::ToInt32(textBoxThresh->Text);
		//double threshold = 128;

		// declaration of BitMap object for results
		Bitmap^ threshImage;
		threshImage = gcnew Bitmap(image1->Width, image1->Height);

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ threshImageData;

		// Lock the image
		threshImageData = threshImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// thresh, set int ptr to the front of the image
		threshResultPtr = threshImageData->Scan0;
		Gr = (Byte*)((Void*)threshResultPtr);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		// process all pixel
		for (int y = 0; y < topImage->Height; y++)
		{
			for (int x = 0; x < topImage->Width; x++)
			{
				int pixel;
				// Threshold filter
				if (p[0] > threshold || p[1] > threshold || p[2] > threshold) {
					pixel = 255;
					Gr[0] = (Byte)pixel;
					Gr[1] = (Byte)pixel;
					Gr[2] = (Byte)pixel;
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
		topImage->UnlockBits(ImageData1);
		threshImage->UnlockBits(threshImageData);

		// show it on the pictureBox
		picture_box2->Image = threshImage;
		image_list[image_list_idx++] = threshImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);
		
		// Byte ptr array
		Byte* r[9]; 

		// Array for pixel value and pixel index
		int Array[9] = { 0 };
	
		for (int y = 0; y < image1->Height; y++) 
		{
			for (int x = 0; x < image1->Width; x++) 
			{
				// not dealing with boundary cases
				if (y > 0 && x > 0 && y < image1->Height - 1 && x < image1->Width - 1)
				{
					int Masksize = 0;
					//save pixel value for calculating
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -3; j <= 3; j += 3)
						{
							// point the ptr to the target
							r[Masksize] = (Byte*)(Void*)p + i * image1->Width * 3 + j;
							// save pixel
							Array[Masksize] = (r[Masksize][0] * 11 + r[Masksize][1] * 59 + r[Masksize][2] * 30 + 50) / 100;
							Masksize++;
						}
					}
					int value = Array[0] + 2 * Array[1] + Array[2] - Array[6] - 2 * Array[7] - Array[8];
					
					sobelV[0] = value;
					sobelV[1] = value;
					sobelV[2] = value;
				}
				else
				{
					sobelV[0] = p[0];
					sobelV[1] = p[1];
					sobelV[2] = p[2];
				}
				sobelV += 3;
				p += 3;
			}
		}


		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		sobelVImage->UnlockBits(sobelVImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelVImage;
		image_list[image_list_idx++] = sobelVImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);
		
		// Byte ptr array
		Byte* r[9]; 

		// Array for pixel value
		int Array[9] = { 0 };
	
		for (int y = 0; y < image1->Height; y++) 
		{
			for (int x = 0; x < image1->Width; x++) 
			{
				// not dealing with boundary cases
				if (y > 0 && x > 0 && y < image1->Height - 1 && x < image1->Width - 1)
				{
					int Masksize = 0;
					//save pixel value for calculating
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -3; j <= 3; j += 3)
						{
							// point the ptr to the target
							r[Masksize] = (Byte*)(Void*)p + i * image1->Width * 3 + j;
							// save pixel
							Array[Masksize] = (r[Masksize][0] * 11 + r[Masksize][1] * 59 + r[Masksize][2] * 30 + 50) / 100;
							Masksize++;
						}
					}
					int value = Array[0] - Array[2] + 2 * Array[3] - 2 * Array[5] + Array[6] - Array[8];
				
					sobelH[0] = value;
					sobelH[1] = value;
					sobelH[2] = value;
				}
				else
				{
					sobelH[0] = p[0];
					sobelH[1] = p[1];
					sobelH[2] = p[2];
				}
				sobelH += 3;
				p += 3;
			}
		}

		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		sobelHImage->UnlockBits(sobelHImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelHImage;
		image_list[image_list_idx++] = sobelHImage;
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

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);
		

		// Byte ptr array
		Byte* r[9]; 

		// Array for pixel value and pixel index
		int Array[9] = { 0 };
	
		for (int y = 0; y < image1->Height; y++) 
		{
			for (int x = 0; x < image1->Width; x++) 
			{
				// not dealing with boundary cases
				if (y > 0 && x > 0 && y < image1->Height - 1 && x < image1->Width - 1)
				{
					int Masksize = 0;
					//save pixel value for calculating
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -3; j <= 3; j += 3)
						{
							// point the ptr to the target
							r[Masksize] = (Byte*)(Void*)p + i * image1->Width * 3 + j;
							// save pixel
							Array[Masksize] = (r[Masksize][0] * 11 + r[Masksize][1] * 59 + r[Masksize][2] * 30 + 50) / 100;
							Masksize++;
						}
					}
					int value_v = Array[0] + 2 * Array[1] + Array[2] - Array[6] - 2 * Array[7] - Array[8];
					int value_h = Array[0] - Array[2] + 2 * Array[3] - 2 * Array[5] + Array[6] - Array[8];
					int value = (int)sqrt(abs(value_v) ^ 2 + abs(value_h) ^ 2);

					sobelC[0] = value;
					sobelC[1] = value;
					sobelC[2] = value;
				}
				else
				{
					sobelC[0] = p[0];
					sobelC[1] = p[1];
					sobelC[2] = p[2];
				}
				sobelC += 3;
				p += 3;
			}
		}

		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		sobelCImage->UnlockBits(sobelCImageData);

		// show it on the pictureBox
		picture_box2->Image = sobelCImage;
		image_list[image_list_idx++] = sobelCImage;
	}
	
	private: System::Void buttonOverlap_Click(System::Object^ sender, System::EventArgs^ e) {

		// Image area
		Rectangle rect;
		//設定rect
		rect = Rectangle(0, 0, image1->Width, image1->Height);
		
		// declaration of BitMap object for results
		Bitmap^ overlapImage;
		overlapImage = image1->Clone(rect, image1->PixelFormat);
		
		Bitmap^ topImage;
		topImage = image_list[image_list_idx-1]->Clone(rect, image1->PixelFormat);

		Color Px;

		for (int y = 0; y < image1->Height; y++) 
		{
			for (int x = 0; x < image1->Width; x++) 
			{
				if (topImage->GetPixel(x, y).R == 255)
					overlapImage->SetPixel(x, y, Px.FromArgb(0, 255, 0));
			}
		}

		// show it on the pictureBox
		picture_box2->Image = overlapImage;
	}
	

	private: System::Void buttonConnected_Click(System::Object^ sender, System::EventArgs^ e) {
		// Threshold Filter 

		// declaration of BitMap object for results
		Bitmap^ connectedImage;
		connectedImage = gcnew Bitmap(image1->Width, image1->Height);
		
		// labeling conneceted components
		int noElem = 0;
		Color Px;
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				connectedImage->SetPixel(x, y, Px.FromArgb(255, 255, 255));
			}
		}
		for (int y = 0; y < image1->Height; y++) 
		{
			for (int x = 0; x < image1->Width; x++) 
			{
				if ((image1->GetPixel(x, y).R != 255) && (connectedImage->GetPixel(x, y).R == 255))
					connectedComponents(x, y, ++noElem, image1, connectedImage);
					//connectedImage->SetPixel(x, y, Px.FromArgb(0, 255, 0));
				/*
				else if ((image1->GetPixel(x, y).R == 255))
					connectedImage->SetPixel(x, y, Px.FromArgb(255, 255, 0));
				*/
			}
		}
		

		// show it on the pictureBox
		picture_box2->Image = connectedImage;
		label1->Text = String::Format("Number of Components : {0}", noElem);
	}
	private: System::Void connectedComponents(int row, int col, int current_label, Bitmap^ bmp, Bitmap^ bmpTmp)
	{
		if (row < 0 || row == bmpTmp->Width) return;
		if (col < 0 || col == bmpTmp->Height) return;
		if ((bmp->GetPixel(row, col).R == 255) || bmpTmp->GetPixel(row, col).R != 255) return;

		Color Px;
		const int dx[] = { +1, 0, -1, 0, -1, 1, 1, -1 };
		const int dy[] = { 0, +1, 0, -1, -1, 1, -1, 1 };
		int color_label = (current_label * 5) % 255;
		bmpTmp->SetPixel(row, col, Px.FromArgb(color_label, color_label, color_label));

		for (int direction = 0; direction < 8; ++direction)
			connectedComponents(row + dx[direction], col + dy[direction], current_label, bmp, bmpTmp);
	}

	private: System::Void buttonRegistration_Click(System::Object^ sender, System::EventArgs^ e) {

		// declaration of BitMap object for results
		Bitmap^ RegistrationImage;
		RegistrationImage = gcnew Bitmap(image1->Width, image1->Height);

		// find Homography
		float P[8][9] =
		{
			{-point_list[0]->X, -point_list[0]->Y, -1,   0,   0,  0, point_list[0]->X * point_list[4]->X, point_list[0]->Y * point_list[4]->X, -point_list[4]->X }, // h11
			{  0,   0,  0, -point_list[0]->X, -point_list[0]->Y, -1, point_list[0]->X * point_list[4]->Y, point_list[0]->Y * point_list[4]->Y, -point_list[4]->Y }, // h12

			{-point_list[1]->X, -point_list[1]->Y, -1,   0,   0,  0, point_list[1]->X * point_list[5]->X, point_list[1]->Y * point_list[5]->X, -point_list[5]->X }, // h13
			{  0,   0,  0, -point_list[1]->X, -point_list[1]->Y, -1, point_list[1]->X * point_list[5]->Y, point_list[1]->Y * point_list[5]->Y, -point_list[5]->Y }, // h21

			{-point_list[2]->X, -point_list[2]->Y, -1,   0,   0,  0, point_list[2]->X * point_list[6]->X, point_list[2]->Y * point_list[6]->X, -point_list[6]->X }, // h22
			{  0,   0,  0, -point_list[2]->X, -point_list[2]->Y, -1, point_list[2]->X * point_list[6]->Y, point_list[2]->Y * point_list[6]->Y, -point_list[6]->Y }, // h23

			{-point_list[3]->X, -point_list[3]->Y, -1,   0,   0,  0, point_list[3]->X * point_list[7]->X, point_list[3]->Y * point_list[7]->X, -point_list[7]->X }, // h31
			{  0,   0,  0, -point_list[3]->X, -point_list[3]->Y, -1, point_list[3]->X * point_list[7]->Y, point_list[3]->Y * point_list[7]->Y, -point_list[7]->Y }, // h32
		};

		gaussian_elimination(&P[0][0], 9);

		// gaussian elimination gives the results of the equation system
		// in the last column of the original matrix.
		// opengl needs the transposed 4x4 matrix:
		float aux_H[] = { P[0][8], P[1][8], P[2][8],	// h11  h21 0 h31
						P[3][8], P[4][8], P[5][8],	// h12  h22 0 h32
						P[6][8], P[7][8], 1 };		// h13  h23 0 h33

		float a = aux_H[0];
		float b = aux_H[1];
		float c = aux_H[2];
		float d = aux_H[3];
		float e_ = aux_H[4];
		float f = aux_H[5];

		float p_ = sqrt(a * a + b * b);
		float r_ = (a * e_ - b * d) / (p_);
		float q = (a * d + b * e_) / (a * e_ - b * d);

		float translation_x = c;
		float translation_y = f;
		float scale_x = p_;
		float scale_y = r_;
		float shear = q;
		float angle = atan2(b, a);

		label7->Text = String::Format("Scaling Factor x :{0}, y:{1},", scale_x, scale_y);
		label8->Text = String::Format("Rotating Angle {0}", angle);

		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				int x_after = x * aux_H[0] + y * aux_H[3] + aux_H[6];
				int y_after = x * aux_H[1] + y * aux_H[4] + aux_H[7];
				RegistrationImage->SetPixel(x_after, y_after, image1->GetPixel(x, y));
			}
		}

		// declaration of BitMap object for pixels of results
		Imaging::BitmapData^ RegistrationImageData;

		// Lock the image
		RegistrationImageData = RegistrationImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);

		// Gray, set int ptr to the front of the image
		RegistrationResultPtr = RegistrationImageData->Scan0;
		Registration = (Byte*)((Void*)RegistrationResultPtr);

		Bitmap^ topImage;
		topImage = image_list[image_list_idx - 1]->Clone(rect, image1->PixelFormat);

		// Lock the original image
		ImageData1 = topImage->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, image1->PixelFormat);
		// set int ptr to the front of the image
		ptr = ImageData1->Scan0;
		// ptr initialization
		p = (Byte*)((Void*)ptr);

		int total_pixels = 0;
		int sum = 0;
		for (int y = 0; y < image1->Height; y++)
		{
			for (int x = 0; x < image1->Width; x++)
			{
				total_pixels++;
				sum += abs(Registration[0] - p[0]);
				Registration += 3;
				p += 3;
			}
		}
		float pixel_intensity = sum / total_pixels;

		label9->Text = String::Format("Intensity Difference {0}", pixel_intensity);

		
		// Unlock pixel
		topImage->UnlockBits(ImageData1);
		RegistrationImage->UnlockBits(RegistrationImageData);

		// show it on the pictureBox
		picture_box2->Image = RegistrationImage;
		image_list[image_list_idx++] = RegistrationImage;
	}

public:System::Void picture_box1_Click(System::Object^ sender, MouseEventArgs^ e)
	{
		coordinates = e->Location;
		if (point_list_idx > 3)
			point_list_idx = 0;
		point_list[point_list_idx++] = coordinates;
		label7->Text = String::Format("click {0}", coordinates.X);
	}

public:System::Void picture_box2_Click(System::Object^ sender, MouseEventArgs^ e)
	{
		coordinates = e->Location;
		if (point_list_idx > 7)
			point_list_idx = 4;
		point_list[point_list_idx++] = coordinates;
	}

private: static void gaussian_elimination(float* input, int n)
	{
		float* A = input;
		int i = 0;
		int j = 0;
		//m = 8 rows, n = 9 cols
		int m = n - 1;
		while (i < m && j < n)
		{
			// Find pivot in column j, starting in row i:
			int maxi = i;
			for (int k = i + 1; k < m; k++)
			{
				//select largest
				if (fabs(A[k * n + j]) > fabs(A[maxi * n + j]))
				{
					maxi = k;
				}
			}
			if (A[maxi * n + j] != 0)
			{
				//swap rows i and maxi, but do not change the value of i
				if (i != maxi)
					for (int k = 0; k < n; k++)
					{
						float aux = A[i * n + k];
						A[i * n + k] = A[maxi * n + k];
						A[maxi * n + k] = aux;
					}
				//Now A[i,j] will contain the old value of A[maxi,j].
				//divide each entry in row i by A[i,j]
				float A_ij = A[i * n + j];
				for (int k = 0; k < n; k++)
				{
					A[i * n + k] /= A_ij;
				}
				//Now A[i,j] will have the value 1.
				for (int u = i + 1; u < m; u++)
				{
					//subtract A[u,j] * row i from row u
					float A_uj = A[u * n + j];
					for (int k = 0; k < n; k++)
					{
						A[u * n + k] -= A_uj * A[i * n + k];
					}
					//Now A[u,j] will be 0, since A[u,j] - A[i,j] * A[u,j] = A[u,j] - 1 * A[u,j] = 0.
				}
				i++;
			}
			j++;
		}

		//back substitution
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				A[i * n + m] -= A[i * n + j] * A[j * n + m];
			}
		}

	}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
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
		image2 = safe_cast<Bitmap^>(Image::FromFile(openFileDialog1->FileName));
		//設定rect
		rect = Rectangle(0, 0, image2->Width, image2->Height);
		//將影像顯示在picture_box1
		picture_box2->Image = image2;
	}
}
};
}
