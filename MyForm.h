#pragma once

// #include "Cocktails2.h"
// #include "main.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary of MyForm Information
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clear all used resources.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	protected:

	private:
		/// <summary>
		/// Designer variable required.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Method required to support the designer - should not be modified
		/// its contents in the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(39, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Gin Tonic";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(236, 52);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(89, 53);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Gin Hass";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(422, 52);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 53);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Screwdriver";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(39, 242);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(89, 53);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Black Russian";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(236, 242);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(89, 53);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Summer Collins";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(422, 242);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(89, 53);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Clean";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 331);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// cocktails.ginHass();
	}
};
}
