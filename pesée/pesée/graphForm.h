
#pragma once
#include <string>

namespace pesée {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Description résumée de graphForm
	/// </summary>
	public ref class graphForm : public System::Windows::Forms::Form
	{
	public:
		double ****DATA;
		double zoom;
		unsigned __int64 ***NUMdatavalues;
		array<array<array<array<Point>^>^>^>^ curvePoints;
		unsigned __int64 **NUMChannels;
		unsigned int *NUMGroups,NUMFiles;
		unsigned int cGroups,cChannels,cFiles,cGraph;//Counter
		array<Color>^ colors;
		List<int>^ gc;
			
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  resetToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	public: 

		graphForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~graphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  selectToolStripMenuItem;

	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->selectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Desktop;
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(650, 285);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &graphForm::drawCurve);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->selectToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(634, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// selectToolStripMenuItem
			// 
			this->selectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->resetToolStripMenuItem
			});
			this->selectToolStripMenuItem->Name = L"selectToolStripMenuItem";
			this->selectToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->selectToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &graphForm::menustrip_save);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(65, 331);
			this->textBox1->MaxLength = 6;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 329);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Actualiser";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &graphForm::Actualiser);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Zoom X";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(65, 357);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(55, 20);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 363);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Fichier";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(137, 363);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Groupe";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(185, 357);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(61, 20);
			this->numericUpDown2->TabIndex = 8;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(268, 363);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Chaîne";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(316, 356);
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(63, 20);
			this->numericUpDown3->TabIndex = 10;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(405, 353);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Ajouter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &graphForm::Ajouter);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->resetToolStripMenuItem->Text = L"Reset";
			// 
			// graphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 411);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"graphForm";
			this->Text = L"Show Graph";
			this->Load += gcnew System::EventHandler(this, &graphForm::OnLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void OnLoad(Object^ sender, System::EventArgs^ e)
		{
			graphForm::zoom = 1.0;
			cFiles = 1;
			cGroups = 1;
			cChannels = 1;
			cGraph = 1;

			colors = gcnew array<Color>(10);
			colors[0] = Color::Red;
			colors[1] = Color::Yellow;
			colors[2] = Color::Blue;
			colors[3] = Color::Green;
			colors[4] = Color::Purple;
			colors[5] = Color::Orange;
			colors[6] = Color::Pink;

			gc = gcnew List<int>();
			gc->Add(0);
			gc->Add(0);
			gc->Add(0);
		}

			void menustrip_save( Object^ sender, System::EventArgs^ e)
			{
				Stream^ myStream;
				SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				saveFileDialog1->Filter = "BMP files (*.bmp)|*.bmp";
				saveFileDialog1->FilterIndex = 2;
				saveFileDialog1->RestoreDirectory = true;
				if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				{
					if ( (myStream = saveFileDialog1->OpenFile()) != nullptr )
					{
						myStream->Close();
						//Code to write the stream goes here.
						String^ path = saveFileDialog1->FileName;
						Bitmap^ bmp = gcnew Bitmap(this->pictureBox1->Width,this->pictureBox1->Height);
						this->pictureBox1->DrawToBitmap(bmp, this->pictureBox1->ClientRectangle);
						bmp->Save(path);
					}
				}
			}

		void drawCurve( Object^ sender, System::Windows::Forms::PaintEventArgs^ e )
		{
			Graphics^ g = e->Graphics;
			int i;
			for (i = 0; i < cGraph; i++)
			{
				Pen^ curvePen = gcnew Pen(colors[i],2.0F);
				g->DrawCurve(curvePen, curvePoints[gc[3*i]][gc[3*i+1]][gc[3*i+2]], 1.0);
			}
		}

		array<Point>^ convertDatatoPoints(double* data, unsigned __int64 numDataValues)
		{
			double x=5,y=0;
			double tmp;
			int i;
			array<Point>^ curvePoints = gcnew array<Point>(numDataValues);
			for(i=0;i<numDataValues;i++)
			{
				tmp=data[i];
				y = 220-20*tmp;
				x = x + 5*zoom;
				curvePoints[i] = Point(x,y);
			}
			return curvePoints;
		}

		void drawCoordinate( Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			Pen^ coordinatePen = gcnew Pen(Color::White,1.0F);
			Graphics^ g= e->Graphics;
			Point origin = Point(10,220);
			Point endX = Point(600,220);
			Point endY = Point(10,0);
			g->DrawLine(coordinatePen,origin,endX);
			g->DrawLine(coordinatePen,origin,endY);
		}

		void Actualiser(Object^ sender, System::EventArgs^ e)
		{
			String ^n = this->textBox1->Text;
			graphForm::zoom = System::Convert::ToDouble(n);
			converte();
			this->pictureBox1->Refresh();
		}

		void Ajouter(Object^ sender, System::EventArgs^ e)
		{
			cFiles = System::Convert::ToInt32(this->numericUpDown1->Text);
			cGroups = System::Convert::ToInt32(this->numericUpDown2->Text);
			cChannels = System::Convert::ToInt32(this->numericUpDown3->Text);
			if (cFiles <= NUMFiles)
			{
				if (cGroups <= NUMGroups[cFiles-1])
				{
					if (cChannels <= NUMChannels[cFiles - 1][cGroups - 1])
					{
						gc->Add(cFiles - 1);
						gc->Add(cGroups - 1);
						gc->Add(cChannels - 1);
						cGraph++;
						this->pictureBox1->Refresh();
						return;
					}
				}
			}
				MessageBox::Show("Error:out of range!");
		}

		void cleanPicture( Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			Graphics^ g= e->Graphics;
			g->Clear(Color::Black);
		}

		void converte()
		{
			int a, b, c;//counters
			for (c = 0; c < NUMFiles; c++)
			{
				for (a = 0; a < NUMGroups[c]; a++)
				{
					for (b = 0; b < NUMChannels[c][a]; b++)
					{
						delete []curvePoints[c][a][b];
						curvePoints[c][a][b] = convertDatatoPoints(DATA[c][a][b],
							NUMdatavalues[c][a][b]);
					}
				}
			}
		}
	};
}
