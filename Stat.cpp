#include <vcl.h>
#pragma hdrstop
#include "Stat.h"
#include <stdlib.h>
#include <fstream.h>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
__fastcall TForm6::TForm6(TComponent* Owner) : TForm(Owner){ }
//---------------------------------------------------------------------------

String fresult = "results.txt";

struct Person
{
    String name; // ���
    int time;                   // ����������� �����
    String fileName;
    String level;
    int countMistakes;
} p;

void __fastcall TForm6::FormCreate(TObject *Sender)
{         /*
        StringGrid1->ColCount = 5;
        StringGrid1->RowCount = 5;
        StringGrid1->FixedCols = 0;
        StringGrid1->FixedRows = 1;
        StringGrid1->Cells[0][0] = "���";
        StringGrid1->Cells[1][0] = "�����";
        StringGrid1->Cells[2][0] = "�������";
        StringGrid1->Cells[3][0] = "���������";
        StringGrid1->Cells[4][0] = "��������� ������";
        StringGrid1->ColWidths[0] = 120;
        StringGrid1->ColWidths[1] = 120;
        StringGrid1->ColWidths[2] = 120;
        StringGrid1->ColWidths[3] = 120;
        StringGrid1->ColWidths[4] = 120;

        //StringGrid1->Options = StringGrid1->Options << goEditing;
        FILE *fr = fopen(fresult.c_str(), "rt");
        if(!fr) {perror(fresult.c_str()); exit(1);}

        int count = 1;
        while(!feof(fr))
        {
                fread(&p, sizeof(Person),1,fr);

                StringGrid1->Cells[0][count] = p.name;
                StringGrid1->Cells[1][count] = p.time;
                StringGrid1->Cells[2][count] = p.fileName;
                StringGrid1->Cells[3][count] = p.level;
                StringGrid1->Cells[4][count] = p.countMistakes;

                ++count;
                fscanf(fr,"\n");
        }
        //CountPerson = count - 1;

        fclose(fr);
        //StringGrid1->Options = StringGrid1->Options >> goEditing;    */
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormShow(TObject *Sender)
{
        StringGrid1->ColCount = 5;
        StringGrid1->RowCount = 2;
        StringGrid1->FixedCols = 0;
        StringGrid1->FixedRows = 1;
        StringGrid1->Cells[0][0] = "���";
        StringGrid1->Cells[1][0] = "�����";
        StringGrid1->Cells[2][0] = "�������";
        StringGrid1->Cells[3][0] = "���������";
        StringGrid1->Cells[4][0] = "��������� ������";
        StringGrid1->ColWidths[0] = 120;
        StringGrid1->ColWidths[1] = 120;
        StringGrid1->ColWidths[2] = 120;
        StringGrid1->ColWidths[3] = 120;
        StringGrid1->ColWidths[4] = 120;

        StringGrid1->Options = StringGrid1->Options << goEditing;
        FILE *fr = fopen(fresult.c_str(), "rb");
        if(!fr) {perror(fresult.c_str()); exit(1);}

        int count = 1;
        while(!feof(fr))
        {       
                StringGrid1->RowCount++;

                fread(&p, sizeof(Person),1,fr);

                StringGrid1->Cells[0][count] = p.name;
                StringGrid1->Cells[1][count] = p.time;
                StringGrid1->Cells[2][count] = p.fileName;
                StringGrid1->Cells[3][count] = p.level;
                StringGrid1->Cells[4][count] = p.countMistakes;

                ++count;
                fscanf(fr,"\n");
        }
        //CountPerson = count - 1;

        fclose(fr);
        //StringGrid1->Options = StringGrid1->Options >> goEditing;
}
//---------------------------------------------------------------------------

