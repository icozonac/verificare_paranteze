#pragma once

namespace verificareparanteze {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::string toStandardString(System::String^ string)
	{
		using System::Runtime::InteropServices::Marshal;

		if (string->Length == 0 || string->Length < 0)
		{
			MessageBox::Show("No field can be empty");

		}

		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);


		return returnString;
	}

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ expresia;
	private: System::Windows::Forms::Button^ buton1;
	private: System::Windows::Forms::Button^ buton2;
	private: System::Windows::Forms::Label^ out;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->expresia = (gcnew System::Windows::Forms::TextBox());
			this->buton1 = (gcnew System::Windows::Forms::Button());
			this->buton2 = (gcnew System::Windows::Forms::Button());
			this->out = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(207, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(307, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Introduceți expresia aritmetică";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// expresia
			// 
			this->expresia->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->expresia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->expresia->Location = System::Drawing::Point(98, 154);
			this->expresia->Multiline = true;
			this->expresia->Name = L"expresia";
			this->expresia->Size = System::Drawing::Size(536, 53);
			this->expresia->TabIndex = 1;
			this->expresia->TextChanged += gcnew System::EventHandler(this, &MyForm::expresia_TextChanged);
			// 
			// buton1
			// 
			this->buton1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buton1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buton1->Location = System::Drawing::Point(228, 278);
			this->buton1->Name = L"buton1";
			this->buton1->Size = System::Drawing::Size(239, 58);
			this->buton1->TabIndex = 2;
			this->buton1->Text = L"Verificare";
			this->buton1->UseVisualStyleBackColor = true;
			this->buton1->Click += gcnew System::EventHandler(this, &MyForm::buton1_Click);
			// 
			// buton2
			// 
			this->buton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buton2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buton2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buton2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buton2->Location = System::Drawing::Point(228, 353);
			this->buton2->Name = L"buton2";
			this->buton2->Size = System::Drawing::Size(239, 37);
			this->buton2->TabIndex = 3;
			this->buton2->Text = L"Ștergere";
			this->buton2->UseVisualStyleBackColor = false;
			this->buton2->Click += gcnew System::EventHandler(this, &MyForm::buton2_Click);
			// 
			// out
			// 
			this->out->AutoSize = true;
			this->out->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->out->Location = System::Drawing::Point(224, 443);
			this->out->Name = L"out";
			this->out->Size = System::Drawing::Size(0, 22);
			this->out->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 515);
			this->Controls->Add(this->out);
			this->Controls->Add(this->buton2);
			this->Controls->Add(this->buton1);
			this->Controls->Add(this->expresia);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(753, 562);
			this->MinimumSize = System::Drawing::Size(753, 562);
			this->Name = L"MyForm";
			this->Text = L"Verificare paranteze";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
public: System::Void expresia_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	  }
	
private: System::Void buton1_Click(System::Object^ sender, System::EventArgs^ e) {
	   
	   String^ expresie = this->expresia->Text;
	   
	   string std_expresie = toStandardString(expresie);
	   
	   Mystack stack1;
	   
	   if (VerificateExpressions(std_expresie))
		   this->out->Text = "Nu este o expresie aritmetica";
	   else 
		   if (AreParantheses(std_expresie) == 0)
			   this->out->Text = "Expresia e corecta, dar nu are nici o paranteza";
		   else
		   if (AreParanthesesBalanced(std_expresie, stack1))
			   this->out->Text = "Parantezele au fost inchise corect";
		   else
			   this->out->Text = "Parantezele nu au fost inchise corect";
	   
	}
private: System::Void buton2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->expresia->Text = "";
	this->out->Text = "";
}
};
}
