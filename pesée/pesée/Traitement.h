#pragma once

#include "writefile.h"

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
	/// Summary for Traitement
	/// </summary>
	public ref class Traitement : public System::Windows::Forms::Form
	{
	public:
		double ****DATA;
		unsigned __int64 ***NUMdatavalues;
		unsigned __int64 **NUMChannels;
		unsigned int *NUMGroups, NUMFiles;
		double ***parts;
		int **numbers;
		int *NUMParts;
		double signe;
		Timestamp ***starttime;
		Timestamp **partstime;
		array<List<int>^>^ positions;
		char **FileName;

	private: System::Windows::Forms::ToolStripMenuItem^  traiterToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  enregistrerToolStripMenuItem;
	public:
		Traitement(void)
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
		~Traitement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;

	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->traiterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enregistrerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(0, 27);
			this->textBox1->Margin = System::Windows::Forms::Padding(0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(484, 438);
			this->textBox1->TabIndex = 0;
			this->textBox1->WordWrap = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Traitement::textBox1_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GrayText;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(0);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(484, 27);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->traiterToolStripMenuItem,
					this->enregistrerToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(60, 23);
			this->fileToolStripMenuItem->Text = L"Fichier";
			// 
			// traiterToolStripMenuItem
			// 
			this->traiterToolStripMenuItem->Name = L"traiterToolStripMenuItem";
			this->traiterToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->traiterToolStripMenuItem->Text = L"Traiter";
			this->traiterToolStripMenuItem->Click += gcnew System::EventHandler(this, &Traitement::traiterToolStripMenuItem_Click);
			// 
			// enregistrerToolStripMenuItem
			// 
			this->enregistrerToolStripMenuItem->Name = L"enregistrerToolStripMenuItem";
			this->enregistrerToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->enregistrerToolStripMenuItem->Text = L"Enregistrer";
			this->enregistrerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Traitement::enregistrerToolStripMenuItem_Click);
			// 
			// Traitement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 461);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Traitement";
			this->Text = L"Traitement";
			this->Load += gcnew System::EventHandler(this, &Traitement::Traitement_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void Traitement_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			signe = -100;
		}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: 
		System::Void traiterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			int front, end, count,stat;
			int cFiles, cGroups, cChannels;
			array<List<double>^>^ cuts;
			cuts = gcnew array<List<double>^>(NUMFiles);
			positions = gcnew array<List<int>^>(NUMFiles);
			parts = new double**[NUMFiles];
			NUMParts = new int[NUMFiles];
			numbers = new int*[NUMFiles];
			partstime = new Timestamp *[NUMFiles];
			this->textBox1->AppendText("En cours de traitement...\n");
			for (cFiles = 0; cFiles < NUMFiles; cFiles++)
			{
				stat = 0;
				cuts[cFiles] = gcnew List<double>();
				positions[cFiles] = gcnew List<int>();
				for (cGroups = 0; cGroups < NUMGroups[cFiles]; cGroups++)
				{
					for (cChannels = 0; cChannels < NUMChannels[cFiles][cGroups]; cChannels++)
					{
						front = end = count = 0;
						while (front < NUMdatavalues[cFiles][cGroups][cChannels])
						{
							if (count == 3)
							{
								while (count != 0 && front < NUMdatavalues[cFiles][cGroups][cChannels])
								{
									if (DATA[cFiles][cGroups][cChannels][front] <= 1.0)
										count--;
									front++;
								}
								int i;
								for (i = 0; i < front-end+1; i++)
								{
									cuts[cFiles]->Add(DATA[cFiles][cGroups][cChannels][end+i]);
								}
								cuts[cFiles]->Add(signe);
								positions[cFiles]->Add(end);//Stocker la position de chaque partie,pour calculer "start time"
								stat++;
								end = front;
							}
							else if (DATA[cFiles][cGroups][cChannels][front] >= 1.0)
							{
								count++;
								front++;
							}
							else
							{
								count = 0;
								front++;
								end = front;
							}
						}
					}
				}
				textBox1->AppendText(Convert::ToString(stat) + " parties utiles.\n");
				textBox1->AppendText("\n");
				parts[cFiles] = new double*[stat];
				numbers[cFiles] = new int[stat];
				partstime[cFiles] = new Timestamp[stat];
				NUMParts[cFiles] = stat;
				int n = 0, num = 0, i;
				front = end = 0;
				int k;
				int minute, second;
				double milliSecond;
				int cp;//current position
				Timestamp cps;
				cps = starttime[cFiles][0][0];
				/*for (k = 0; k < 200; k++)
				{
					textBox1->AppendText(Convert::ToString(cuts[cFiles][k] + "\n"));
				}*/
				for (n = 0; n < stat; n++)
				{
					while (cuts[cFiles][front] != signe)
					{
						front++;
					}
					num = front - end;
					parts[cFiles][n] = new double[num];
					for (i = 0; i < num; i++)
					{
						parts[cFiles][n][i] = cuts[cFiles][end+i];
					}
					//Calculer et stocker l'information du temps
					numbers[cFiles][n] = num;
					cp = positions[cFiles][n];
					minute = cp / 6000;
					second = (cp % 6000) / 100;
					milliSecond = cp % 6000 % 100;
					partstime[cFiles][n].minute = cps.minute + minute;
					partstime[cFiles][n].second = cps.second + second;
					partstime[cFiles][n].milliSecond = cps.milliSecond + milliSecond;
					partstime[cFiles][n].hour = cps.hour;
					partstime[cFiles][n].day = cps.day;
					partstime[cFiles][n].month = cps.month;
					partstime[cFiles][n].year = cps.year;


					front++;
					end = front;
					textBox1->AppendText("Fichier "+Convert::ToString(cFiles + 1) + " Partie " + Convert::ToString(n + 1) + "\n");
					textBox1->AppendText("Nombre de données utiles: " + Convert::ToString(num) + "\n");
					
					String ^sproperty;
					Timestamp cgs = partstime[cFiles][n];
					sproperty = gcnew String(Convert::ToString(cgs.year) + "-" + Convert::ToString(cgs.month) + "-" +
						Convert::ToString(cgs.day) + " " + Convert::ToString(cgs.hour) + ":" + Convert::ToString(cgs.minute)
						+ ":" + Convert::ToString(cgs.second) + ":" + Convert::ToString((int)cgs.milliSecond));
					this->textBox1->AppendText(" wf_start_time: \n" +
						sproperty + "\n");
					this->textBox1->AppendText(Convert::ToString(cp) + "\n");
					textBox1->AppendText("\n");
					delete[]sproperty;
				}
			}
			textBox1->AppendText("Traitement Success!\n");
		}
private: 
	System::Void enregistrerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Stream^ myStream;
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
		saveFileDialog1->Filter = "TDMS files (*.TDMS)|*.TDMS";
		saveFileDialog1->FilterIndex = 2;
		saveFileDialog1->RestoreDirectory = true;
		char *FILE_PATH = NULL;

		int						ddcError = 0;
		DDCFileHandle			file = 0;
		DDCChannelGroupHandle	*group;
		group = new DDCChannelGroupHandle[NUMFiles];
		DDCChannelHandle		**channels;
		channels = new DDCChannelHandle*[NUMFiles];
		int i, j, k;

		for (i = 0; i < NUMFiles; i++)
		{
			channels[i] = new DDCChannelHandle[NUMParts[i]];
		}

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
			{
				// Code to write the stream goes here.
				myStream->Close();
				String^ path = saveFileDialog1->FileName;
				int length = path->Length;
				FILE_PATH = (char*)malloc((length + 1)*sizeof(char));
				for (i = 0; i<length; i++)
				{
					FILE_PATH[i] = path[i];
				}
				FILE_PATH[i] = '\0';
				char *FILE_NAME;
				for (i = 0; i < length + 1; i++)
				{
					if (FILE_PATH[length - i] == '\\')
						break;
				}
				FILE_NAME = new char[i];
				for (j = 0; j < i; j++)
				{
					FILE_NAME[j] = FILE_PATH[length + 1 - i + j];
				}

				static const char *	FILE_DESC = "Data File After Traitement";
				static const char *	CHANNEL_UNITS = "Poids";

				// If file exists, delete it.
				remove(FILE_PATH);
				// Create file and add channel group and channels.
				ddcChk(DDC_CreateFile(FILE_PATH, "TDMS", FILE_NAME, FILE_DESC, "", "", &file));
				for (i = 0; i < NUMFiles; i++)
				{
					ddcChk(DDC_AddChannelGroup(file, FileName[i], NULL, &group[i]));
					for (j = 0; j < NUMParts[i]; j++)
					{
						String ^name;
						name = gcnew String("Partie " + Convert::ToString(j + 1));
						char *CHANNEL_NAME = new char[name->Length + 1];
						for (k = 0; k < name->Length; k++)
						{
							CHANNEL_NAME[k] = name[k];
						}
						CHANNEL_NAME[k] = '\0';
						ddcChk(DDC_AddChannel(group[i], DDC_Double, CHANNEL_NAME,
							"", CHANNEL_UNITS, &channels[i][j]));
						delete CHANNEL_NAME;
					}
				}
				for (i = 0; i < NUMFiles; i++)
				{
					for (j = 0; j < NUMParts[i]; j++)
					{
						Timestamp tmp = partstime[i][j];
						ddcChk(DDC_CreateChannelPropertyTimestampComponents(channels[i][j], "wf_start_time", tmp.year, tmp.month, tmp.day, tmp.hour,
							tmp.minute,tmp.second,tmp.milliSecond));
						ddcChk(DDC_SetDataValues(channels[i][j], parts[i][j], numbers[i][j]));
					}
				}
				// Save the file
				ddcChk(DDC_SaveFile(file));
			}
			}
	Error:
		// Close the file and report any errors
		if (file)
			DDC_CloseFile(file);
		if (ddcError < 0)
		{
			String^ ErrorDescription = gcnew String(DDC_GetLibraryErrorDescription(ddcError));
			textBox1->AppendText("\nError: " + ErrorDescription + "\n");
		}
		else
			textBox1->AppendText("\nno errors.\n");
		;
	}
};
}
