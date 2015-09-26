
#pragma once
#include "Traitement.h"
#include "graphForm.h"
#include "readfile.h"
#include <fstream>
#include <iostream>

namespace pesée {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Description résumée de mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		//Références
		double ****DATA;
		unsigned __int64 ***NUMdatavalues;
		array<array<array<array<Point>^>^>^>^ curvePoints;
		unsigned __int64 **NUMChannels;
		unsigned int *NUMGroups;
		unsigned int NUMFiles;
		Timestamp ***starttime;
		unsigned int cGroups,cChannels,cFiles;//Counter
		char **FileName;
		private: System::Windows::Forms::ToolStripMenuItem^  traitementToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	public: 
		mainForm(void)
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
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  graphToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  generateGraphToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;

	protected: 

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->graphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateGraphToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->traitementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GrayText;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->graphToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(672, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->openToolStripMenuItem,
					this->toolStripSeparator1, this->saveToolStripMenuItem, this->traitementToolStripMenuItem, this->closeToolStripMenuItem, this->toolStripSeparator2,
					this->exitToolStripMenuItem
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(46, 25);
			this->toolStripMenuItem1->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::menustrip_open);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(152, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Enabled = false;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::menustrip_save);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Enabled = false;
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::menustrip_close);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(152, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::menustrip_exit);
			// 
			// graphToolStripMenuItem
			// 
			this->graphToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->generateGraphToolStripMenuItem });
			this->graphToolStripMenuItem->Name = L"graphToolStripMenuItem";
			this->graphToolStripMenuItem->Size = System::Drawing::Size(65, 25);
			this->graphToolStripMenuItem->Text = L"Graph";
			// 
			// generateGraphToolStripMenuItem
			// 
			this->generateGraphToolStripMenuItem->Enabled = false;
			this->generateGraphToolStripMenuItem->Name = L"generateGraphToolStripMenuItem";
			this->generateGraphToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->generateGraphToolStripMenuItem->Text = L"Generate Graph";
			this->generateGraphToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::menustrip_generateGraph);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 30);
			this->textBox1->Margin = System::Windows::Forms::Padding(0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(672, 499);
			this->textBox1->TabIndex = 1;
			this->textBox1->WordWrap = false;
			// 
			// traitementToolStripMenuItem
			// 
			this->traitementToolStripMenuItem->Name = L"traitementToolStripMenuItem";
			this->traitementToolStripMenuItem->Size = System::Drawing::Size(155, 26);
			this->traitementToolStripMenuItem->Text = L"Traitement";
			this->traitementToolStripMenuItem->Click += gcnew System::EventHandler(this, &pesée::mainForm::menustrip_traitement);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(672, 530);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"mainForm";
			this->Text = L"Pesée de Manchots";
			this->Load += gcnew System::EventHandler(this, &mainForm::OnLoad);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			void OnLoad(Object^ sender, System::EventArgs^ e)
			{
				mainForm::DATA = nullptr;
				mainForm::NUMChannels = nullptr;
				mainForm::NUMdatavalues = nullptr;
				mainForm::NUMGroups = nullptr;

				mainForm::NUMFiles = 10;
				mainForm::DATA = new double ***[mainForm::NUMFiles];
				mainForm::NUMGroups = new unsigned int[mainForm::NUMFiles];
				mainForm::NUMChannels = new unsigned long long *[mainForm::NUMFiles];
				mainForm::NUMdatavalues = new unsigned long long **[mainForm::NUMFiles];
				mainForm::curvePoints = gcnew array<array<array<array<Point>^>^>^>(mainForm::NUMFiles);
				mainForm::starttime = new Timestamp**[NUMFiles];
				mainForm::FileName = new char*[10];

				mainForm::cChannels = 0;
				mainForm::cFiles = 0;
				mainForm::cGroups = 0;
				this->saveToolStripMenuItem->Enabled = false;
				this->traitementToolStripMenuItem->Enabled = false;
			}

			void menustrip_traitement(Object^ sender, System::EventArgs^ e)
			{
				pesée::Traitement^ traitement = gcnew pesée::Traitement;
				traitement->DATA = DATA;
				traitement->NUMChannels = NUMChannels;
				traitement->NUMGroups = NUMGroups;
				traitement->NUMFiles = cFiles;
				traitement->NUMdatavalues = NUMdatavalues;
				traitement->starttime = starttime;
				traitement->FileName = FileName;
				traitement->ShowDialog();
			}

			void menustrip_close(Object^ sender, System::EventArgs^ e)
			{
				this->textBox1->Clear();
				//
				delete mainForm::DATA;
				delete mainForm::NUMChannels;
				delete mainForm::NUMdatavalues;
				delete mainForm::NUMGroups;
				delete mainForm::starttime;

				mainForm::NUMFiles = 10;
				mainForm::DATA = new double ***[mainForm::NUMFiles];
				mainForm::NUMGroups = new unsigned int[mainForm::NUMFiles];
				mainForm::NUMChannels = new unsigned long long *[mainForm::NUMFiles];
				mainForm::NUMdatavalues = new unsigned long long **[mainForm::NUMFiles];
				mainForm::curvePoints = gcnew array<array<array<array<Point>^>^>^>(mainForm::NUMFiles);
				mainForm::starttime = new Timestamp**[NUMFiles];

				mainForm::cChannels = 0;
				mainForm::cFiles = 0;
				mainForm::cGroups = 0;

				this->closeToolStripMenuItem->Enabled = false;
				this->openToolStripMenuItem->Enabled = true;
				this->generateGraphToolStripMenuItem->Enabled = false;
				this->saveToolStripMenuItem->Enabled = false;
				this->saveToolStripMenuItem->Enabled = false;
				this->traitementToolStripMenuItem->Enabled = false;
			}

			void menustrip_open( Object^ sender, System::EventArgs^ e)
			{
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

				openFileDialog1->Filter = "TDMS Files|*.tdms";
				openFileDialog1->Title = "Select a TDMS File";

				if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				{
					String^ path = openFileDialog1->FileName;
					this->textBox1->AppendText("File Path: "+path+"\n");
					int length = path->Length;
					char *FILE_PATH = NULL;
					FILE_PATH = (char*)malloc((length+1)*sizeof(char));
					int i;
					for(i=0;i<length;i++)
					{
						FILE_PATH[i] = path[i];
					}
					FILE_PATH[i] = '\0';
					int	ddcError = 0;
					ddcChk(ReadFile(FILE_PATH));
					
					int a, b;//counters
					for (a = 0; a < mainForm::NUMGroups[cFiles]; a++)
					{
						for (b = 0; b < mainForm::NUMChannels[cFiles][a]; b++)
						{
							mainForm::curvePoints[cFiles][a][b] = convertDatatoPoints(mainForm::DATA[cFiles][a][b],
								mainForm::NUMdatavalues[cFiles][a][b]);
						}
					}
					
					mainForm::cFiles++;//Ajouter 1 au nombre de fichier
					mainForm::cGroups = 0;

					Error:
						if (ddcError < 0)
							{
								String^ ErrorDescription = gcnew String(DDC_GetLibraryErrorDescription(ddcError));
								this->textBox1->AppendText("\nError: "+ErrorDescription+"\n");
							}
						else
						{
							this->textBox1->AppendText("\nNo errors.\n");
							this->textBox1->AppendText("\n");
							this->closeToolStripMenuItem->Enabled = true;
							//this->openToolStripMenuItem->Enabled = false;
							this->generateGraphToolStripMenuItem->Enabled = true;
							this->saveToolStripMenuItem->Enabled = true;
							this->traitementToolStripMenuItem->Enabled = true;
						}
				}
			}

			void menustrip_save( Object^ sender, System::EventArgs^ e)
			{
				Stream^ myStream;
				SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				saveFileDialog1->FilterIndex = 2;
				saveFileDialog1->RestoreDirectory = true;
				char *FILE_PATH = NULL;
				if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				{
					if ( (myStream = saveFileDialog1->OpenFile()) != nullptr )
					{
						// Code to write the stream goes here.
						myStream->Close();
						String^ path = saveFileDialog1->FileName;
						int length = path->Length;
						FILE_PATH = (char*)malloc((length + 1)*sizeof(char));
						int i;
						for (i = 0; i<length; i++)
						{
							FILE_PATH[i] = path[i];
						}
						FILE_PATH[i] = '\0';
						std::ofstream myfile;
						myfile.open(FILE_PATH);
						for (i = 0; i < NUMdatavalues[0][0][0]; i++)
						{
							myfile << DATA[0][0][0][i] << "\n";
						}
						myfile.close();
					}
				}
			}
		private:
			void menustrip_exit( Object^ sender, System::EventArgs^ e)
			{
				Close();
			}

			void menustrip_generateGraph( Object^ sender, System::EventArgs^ e)
			{
				pesée::graphForm^ graphform = gcnew pesée::graphForm;
				graphform->DATA = DATA;
				graphform->curvePoints = curvePoints;
				graphform->NUMChannels = NUMChannels;
				graphform->NUMGroups = NUMGroups;
				graphform->NUMFiles = cFiles;
				graphform->NUMdatavalues = NUMdatavalues;
				graphform->ShowDialog();
			}

			void test()
			{
				this->textBox1->Clear();
			}

			int ReadFile(char* FILE_PATH)
			{
				int	ddcError = 0;
				unsigned int length;
				DDCFileHandle file = 0;
				char *property = 0;
				String^ sproperty;
				//this->textBox1->AppendText("Test");
				// Read file name
				ddcChk (DDC_OpenFile (FILE_PATH, "TDMS", &file));
				ddcChk (DDC_GetFileStringPropertyLength (file, DDC_FILE_NAME, &length));
				nullChk (property = (char*)malloc (length + 1));
				nullChk (FileName[cFiles] = (char*)malloc(length + 1));
				ddcChk (DDC_GetFileProperty (file, DDC_FILE_NAME, property, length + 1));
				ddcChk(DDC_GetFileProperty(file, DDC_FILE_NAME, FileName[cFiles], length + 1));
				sproperty = gcnew String(property);

				this->textBox1->AppendText("File name property: "+sproperty+"\n");
				free (property);
				delete(sproperty);
				property = 0;

				// Read file description, if present
				if (DDC_GetFileStringPropertyLength (file, DDC_FILE_DESCRIPTION, &length) >= 0)
				{
					nullChk (property =(char*)malloc (length + 1));
					ddcChk (DDC_GetFileProperty (file, DDC_FILE_DESCRIPTION, property, length + 1));
					sproperty = gcnew String(property);

					this->textBox1->AppendText("File description property: "+sproperty+"\n");
					free (property); 
					delete(sproperty);
					property = 0;
				}

				// Read the channel groups
				ddcChk (ReadGroups (file));
				Error:
					if (property)
						free (property);
					if (file)
						DDC_CloseFile (file);
					return ddcError;
			}

			int ReadGroups (DDCFileHandle file)
			{
				int						ddcError = 0;
				unsigned int			length;
				unsigned int			i, numGroups;
				DDCChannelGroupHandle	*groups = 0;
				char					*property = 0;
				String^ sproperty;

				// Get all the channel groups
				ddcChk (DDC_GetNumChannelGroups (file, &numGroups));
				nullChk (groups = (DDCChannelGroupHandle*)calloc (numGroups, sizeof (DDCChannelGroupHandle)));
				ddcChk (DDC_GetChannelGroups (file, groups, numGroups));
				//
				mainForm::NUMChannels[mainForm::cFiles] = new unsigned long long [numGroups];
				mainForm::DATA[mainForm::cFiles] = new double **[numGroups];
				mainForm::NUMdatavalues[mainForm::cFiles] = new unsigned long long *[numGroups];
				mainForm::NUMGroups[mainForm::cFiles] = numGroups;
				mainForm::curvePoints[mainForm::cFiles] = gcnew array<array<array<Point>^>^>(numGroups);
				mainForm::starttime[cFiles] = new Timestamp*[numGroups];

				for (i = 0; i < numGroups; ++i)
				{
					// Read the channel group name
					ddcChk (DDC_GetChannelGroupStringPropertyLength (groups[i], DDC_CHANNELGROUP_NAME, &length));
					nullChk (property = (char*)malloc (length + 1));
					ddcChk (DDC_GetChannelGroupProperty (groups[i], DDC_CHANNELGROUP_NAME, property, length + 1));
					sproperty = gcnew String(property);

					this->textBox1->AppendText("\n");
					this->textBox1->AppendText("Channelgroup #"+Convert::ToString(i+1)+" name property: "
						+sproperty+"\n");
					free(property);
					delete []sproperty;
					property = 0;

				// Read the channel group description, if present
				if (DDC_GetChannelGroupStringPropertyLength (groups[i], DDC_CHANNELGROUP_DESCRIPTION, &length) >= 0)
					{
					nullChk (property =(char*) malloc (length + 1));
					ddcChk (DDC_GetChannelGroupProperty (groups[i], DDC_CHANNELGROUP_DESCRIPTION, 
						property, length + 1));

					this->textBox1->AppendText("Channelgroup #"+Convert::ToString(i+1)+" description property: "
						+sproperty+"\n");
					free (property); 
					delete []sproperty;
					property = 0;
					}

				// Read the channels in this group
				ddcChk (ReadChannels (groups[i]));
				mainForm::cGroups++;
				}

				Error:
					// Cleanup
					if (groups)
						free (groups);
					if (property)
						free (property);
					return ddcError;
			}

			int ReadChannels (DDCChannelGroupHandle group)
			{
				int						ddcError = 0;
				unsigned int			length;
				unsigned int			i, numChannels;
				unsigned __int64		numDataValues;
				DDCChannelHandle		*channels = 0;
				char					*property = 0;
				double					*data = 0, avgDataValue;
				String^ sproperty;

				// Read all the channels in this channel group
				ddcChk (DDC_GetNumChannels (group, &numChannels));
				nullChk (channels = (DDCChannelHandle*)calloc (numChannels, sizeof (DDCChannelHandle)));
				ddcChk (DDC_GetChannels (group, channels, numChannels));
				//
				mainForm::NUMChannels[mainForm::cFiles][mainForm::cGroups] = numChannels;
				mainForm::DATA[mainForm::cFiles][mainForm::cGroups] = new double *[numChannels];
				mainForm::NUMdatavalues[mainForm::cFiles][mainForm::cGroups] = new unsigned long long[numChannels];
				mainForm::curvePoints[mainForm::cFiles][mainForm::cGroups] = gcnew array<array<Point>^>(numChannels);
				mainForm::starttime[mainForm::cFiles][mainForm::cGroups] = new Timestamp[numChannels];
				Timestamp *cgs = mainForm::starttime[cFiles][cGroups];//cgs:current_group_starttime

				for (i = 0; i < numChannels; ++i)
				{
					/*Information Test//
					char **propertyNames = 0;
					char *buffer;
					size_t length;
					DDCDataType *dataType;

					Timestamp starttime;

					DDC_GetChannelPropertyTimestampComponents(channels[i], "wf_start_time",&starttime.year,&starttime.month,&starttime.day,
						&starttime.hour,&starttime.minute,&starttime.second,&starttime.milliSecond,&starttime.weekDay);

					
					unsigned int numberOfProperties,c;
					DDC_GetNumChannelProperties(channels[i], &numberOfProperties);
					propertyNames = (char**)malloc(numberOfProperties * sizeof(char*));
					DDC_GetChannelPropertyNames(channels[i], propertyNames, numberOfProperties);
					this->textBox1->AppendText("numberOfProperties: " + Convert::ToString(numberOfProperties) + "\n");
					for (c = 0; c < numberOfProperties; c++)
					{
						sproperty = gcnew String(propertyNames[c]);
						this->textBox1->AppendText(sproperty + "\n");
					}
					for (c = 0; c < numberOfProperties; c++)
						DDC_FreeMemory(propertyNames[c]);
					free(propertyNames);
					delete[]sproperty;
					*/

					// Read the channel name
					ddcChk (DDC_GetChannelStringPropertyLength (channels[i], DDC_CHANNEL_NAME, &length));
					nullChk (property = (char*)malloc (length + 1));
					ddcChk (DDC_GetChannelProperty (channels[i], DDC_CHANNEL_NAME, property, length + 1));
					sproperty = gcnew String(property);

					this->textBox1->AppendText("\n");
					this->textBox1->AppendText("Channel #"+Convert::ToString(i+1)+" name property: "+
						sproperty+"\n");
					free(property);
					delete []sproperty;
					property = 0;

					// Read the channel description, if present
					if (DDC_GetChannelStringPropertyLength (channels[i], DDC_CHANNEL_DESCRIPTION, &length) >= 0)
					{
						nullChk (property =(char*) malloc (length + 1));
						ddcChk (DDC_GetChannelProperty (channels[i], DDC_CHANNEL_DESCRIPTION, property, length + 1));
						sproperty = gcnew String(property);

						this->textBox1->AppendText("Channel #"+Convert::ToString(i+1)+
							" description property: "+sproperty+"\n");
						free (property); 
						delete []sproperty;
						property = 0;
					}

					// Read the channel units, if present
					if (DDC_GetChannelStringPropertyLength (channels[i], DDC_CHANNEL_UNIT_STRING, &length) >= 0)
					{
						nullChk (property = (char*)malloc (length + 1));
						ddcChk (DDC_GetChannelProperty (channels[i], DDC_CHANNEL_UNIT_STRING, property, length + 1));
						sproperty = gcnew String(property);

						this->textBox1->AppendText("Channel #"+Convert::ToString(i+1)+
							" unit string property: "+sproperty+"\n");
						free (property); 
						delete []sproperty;
						property = 0;
					}
					
					//Read the "wf_start_time" property, if present
					int exists;
					DDC_ChannelPropertyExists(channels[i], "wf_start_time", &exists);
					if (exists == 1)
					{
						DDC_GetChannelPropertyTimestampComponents(channels[i], "wf_start_time", &cgs[i].year, &cgs[i].month, &cgs[i].day, &cgs[i].hour,
							&cgs[i].minute, &cgs[i].second, &cgs[i].milliSecond, &cgs[i].weekDay);
						sproperty = gcnew String(Convert::ToString(cgs[i].year) + "-" + Convert::ToString(cgs[i].month) + "-" +
							Convert::ToString(cgs[i].day) + " " + Convert::ToString(cgs[i].hour) + ":" + Convert::ToString(cgs[i].minute)
							+ ":" + Convert::ToString(cgs[i].second));
						this->textBox1->AppendText("Channel #" + Convert::ToString(i + 1) + " wf_start_time: \n" +
							sproperty + "\n");
						delete[]sproperty;
					}
					
					// Read the channel data
					ddcChk (DDC_GetNumDataValues (channels[i], &numDataValues));
					nullChk (data = (double*)malloc (sizeof (double) * (unsigned int)numDataValues));
					//
					mainForm::DATA[mainForm::cFiles][mainForm::cGroups][i] = new double [numDataValues];
					mainForm::NUMdatavalues[mainForm::cFiles][mainForm::cGroups][i] = numDataValues;
					mainForm::curvePoints[cFiles][cGroups][i] = gcnew array<Point>(numDataValues);
						//(double*)calloc(numDataValues,sizeof(double));
					//
					ddcChk (DDC_GetDataValues (channels[i], 0, (unsigned int)numDataValues, data));
					ddcChk (DDC_GetDataValues (channels[i], 0, (unsigned int)numDataValues, 
						mainForm::DATA[mainForm::cFiles][mainForm::cGroups][i]));
					avgDataValue=GetAvgDataValue(numDataValues,data);


					this->textBox1->AppendText("Channel #"+Convert::ToString(i+1)+
						" number of data values: "+Convert::ToString(numDataValues)+"\n");
					this->textBox1->AppendText("Channel #"+Convert::ToString(i+1)+
						" average data value: "+Convert::ToString(avgDataValue)+"\n");
					ddcChk (DDC_GetChannelStringPropertyLength (channels[i], DDC_CHANNEL_NAME, &length));
					nullChk (property = (char*)malloc (length + 1));
					ddcChk (DDC_GetChannelProperty (channels[i], DDC_CHANNEL_NAME, property, length + 1));
					free(property);
					property=NULL;
				}

			Error:
				// Cleanup
				if (data)
					free (data);
				if (channels)
					free (channels);
				if (property)
					free (property);
				return ddcError;
			}

			double GetAvgDataValue (unsigned __int64 numDataValues, double *data)
			{
				int 	i;
				double 	sum = 0.0;
	
				for (i = 0; i < numDataValues; i++)
					sum += data[i];
	
				return sum / (unsigned int)numDataValues;
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
				x = x + 5;
				curvePoints[i] = Point(x,y);
			}
			return curvePoints;
		}
	};
}
