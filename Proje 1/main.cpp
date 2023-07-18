#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
int main()
{
    int i,j;
    int k;
    initwindow(1539,844);
    int x,y;
    char giris1,giris2,cikis1,cikis2;

    setcolor(15);
    bar(0,0,1538,843);//Arka planı beyaz yapmak icin
    setcolor(BLACK);
    line(769,170,769,844); // Orta çizgisi

    //=======================================================//

    /* SOL TARAF */

    rectangle(150,170,550,570); // Sol taraftaki harita
    setfillstyle(SOLID_FILL,BLACK);
    bar(151,340,549,400); // Sol taraf enine yol
    bar(320,171,380,569); // Sol taraf boyuna yol
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(350,370,100,100); // ortayi bos birakmak için
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(350,370,50,50);
    setcolor(WHITE);
    setlinestyle(1,0,1); // serit yapmak için
    circle(350,370,75); // orta yolun seritleri
    line(150,370,265,370); // t yolu orta seritleri
    line(550,370,435,370); // y yolu orta seritleri
    line(350,170,350,290); // x yolu orta seritleri
    line(350,570,350,450); // z yolu orta seritleri

    setcolor(12);
    setlinestyle(0,0,1);
    line(150,347,260,347); // t yolu üst serit
    line(150,393,260,393); // t yolu alt serit
    line(327,170,327,280); // x yolu sol serit
    line(373,170,373,280); // x yolu sa? serit
    line(550,347,440,347); // y yolu üst serit
    line(550,393,440,393); // y yolu alt serit
    line(327,570,327,460); // z yolu sol serit
    line(373,570,373,460); // z yolu sa? serit

    arc(350,370,14,76,93);
    arc(350,370,104,166,93);
    arc(350,370,194,256,93);        /* KENAR SERITLER */
    arc(350,370,284,346,93);
    circle(350,370,57);


    //========================================================//

    /* SAG TARAF */

    setcolor(BLACK);
    setlinestyle(0,0,1);
    rectangle(988,170,1388,570); // Sag taraftaki harita
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(1188,370,100,100);
    bar(1158,171,1218,569); // Sag taraf boyuna yol
    setcolor(12);
    circle(1188,370,57);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(1188,370,50,50);
    setfillstyle(SOLID_FILL,BLACK);
    bar(989,340,1387,400); // Sag taraf enine yol

    setcolor(WHITE);
    setlinestyle(1,0,1);
    circle(1188,370,75); // çember yolu serit
    line(1146,370,1230,370); // e yolu orta serit
    line(988,370,1113,370); // t yolu orta serit
    line(1388,370,1263,370); // y yolu orta serit
    line(1188,170,1188,295); // x yolu orta serit
    line(1188,570,1188,445); // z yolu orta serit

    setcolor(12);
    setlinestyle(0,0,1);
    line(988,347,1097,347); // t yolu üst serit
    line(988,393,1097,393); // t yolu alt serit
    line(1165,570,1165,461); // z yolu sol serit
    line(1211,570,1211,461); // z yolu sa? serit
    line(1388,347,1279,347); // y yolu üst serit
    line(1388,393,1279,393); // y yolu alt serit
    line(1165,170,1165,279); // x yolu sol serit
    line(1211,170,1211,279); // x yolu sa? serit
    line(1140,347,1236,347); // e yolu üst serit
    line(1140,393,1236,393); // e yolu alt serit
    setcolor(12);
    arc(1188,370,14,76,93);
    arc(1188,370,104,166,93);
    arc(1188,370,194,256,93);        /* KENAR ?ERYTLER */
    arc(1188,370,284,346,93);

    //========================================================//

    /* YAZILAR */

    settextstyle(0,HORIZ_DIR,5);
    outtextxy(378,70,"BIR HARITA SECINIZ!");
    outtextxy(165,650,"1. HARITA");
    outtextxy(1003,650,"2. HARITA");

    settextstyle(3,HORIZ_DIR,3);
    outtextxy(192,352,"t");
    outtextxy(493,352,"y");
    outtextxy(345,210,"x");
    outtextxy(345,510,"z");         /* SOL TARAF YOLLAR */
    outtextxy(285,303,"a");
    outtextxy(395,303,"b");
    outtextxy(290,410,"c");
    outtextxy(390,410,"d");


    outtextxy(1175,352,"e");
    outtextxy(1035,352,"t");
    outtextxy(1325,352,"y");
    outtextxy(1182,210,"x");
    outtextxy(1182,507,"z");        /* SA? TARAF YOLLAR */
    outtextxy(1123,303,"a");
    outtextxy(1233,303,"b");
    outtextxy(1128,410,"c");
    outtextxy(1228,410,"d");

    //========================================================//

    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN,x, y);
    if(x>0 && x<769)
    {
        setfillstyle(SOLID_FILL,15);
        bar(0,0,1538,160);
        bar(770,0,1538,843);
        settextstyle(0,HORIZ_DIR,5);
        outtextxy(165,650,"1. HARITA");
        outtextxy(800,50,"GIRISLERI SECINIZ");
        outtextxy(838,170,"X");
        outtextxy(1038,170,"Y");
        outtextxy(1238,170,"Z");
        outtextxy(1438,170,"T");
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(500);
        }
        getmouseclick(WM_LBUTTONDOWN,x, y);
        if(x>838 && x<888 && y>170 && y<220)/*x giris1*/
        {
            giris1='x';
            outtextxy(938,300,"Y");
            outtextxy(1138,300,"Z");
            outtextxy(1338,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>938 && x<988 && y>300 && y<350)/*y giris2*/
            {
                giris2='y';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Z");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='t';
                }
                else if(x>1238 && x<1188 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='z';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1138 && x<1188 && y>300 && y<350)/* z giris2*/
            {
                giris2='z';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Y");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='t';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='y';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else  if(x>1338 && x<1388 && y>300 && y<350)/*t giris2*/
            {
                giris2='t';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Y");
                outtextxy(1238,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='z';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='y';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(915,450,"HATALI GIRIS");
                outtextxy(970,496,"YAPTINIZ!");
                outtextxy(930,643,"CIKMAK ICIN");
                outtextxy(800,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>1038 && y>170 && x<1088 && y<220)/*y giris1*/
        {
            giris1='y';
            outtextxy(938,300,"X");
            outtextxy(1138,300,"Z");
            outtextxy(1338,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            printf("%d %d",x,y);
            if(x>938 && x<988 && y>300 && y<350)/*x giris2*/
            {
                giris2='x';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Z");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='t';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='z';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1138 && x<1188 && y>300 && y<350)/*z giris2*/
            {
                giris2='z';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='t';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1338 && x<1388 && y>300 && y<350)/*t giris2*/
            {
                giris2='t';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='z';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(915,450,"HATALI GIRIS");
                outtextxy(970,496,"YAPTINIZ!");
                outtextxy(930,643,"CIKMAK ICIN");
                outtextxy(800,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>1238 && x<1288 && y>170 && y<220)/*z giris1*/
        {
            giris1='z';
            outtextxy(938,300,"X");
            outtextxy(1138,300,"Y");
            outtextxy(1338,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>938 && x<988 && y>300 && y<350)/*x giris2*/
            {
                giris2='x';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Y");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='t';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='z';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1138 && x<1188 && y>300 && y<350)/*y giris2*/
            {
                giris2='y';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='t';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1338 && x<1388 && y>300 && y<350)/* t giris2*/
            {
                giris2='t';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"Y");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='y';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(915,450,"HATALI GIRIS");
                outtextxy(970,496,"YAPTINIZ!");
                outtextxy(930,643,"CIKMAK ICIN");
                outtextxy(800,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>1438 && x<1488 && y>170 && y<220)/*t giris1*/
        {
            giris1='t';
            outtextxy(938,300,"X");
            outtextxy(1138,300,"Y");
            outtextxy(1238,300,"Z");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>938 && x<988 && y>300 && y<350)/*x giris2*/
            {
                giris2='x';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"Y");
                outtextxy(1238,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='z';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='y';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1138 && x<1188 && y>300 && y<350)/* y giris2*/
            {
                giris2='y';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='z';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>1338 && x<1388 && y>300 && y<350)/*z giris2*/
            {
                giris2='z';
                bar(770,0,1538,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(800,50,"CIKISLARI SECINIZ");
                outtextxy(1038,270,"X");
                outtextxy(1238,270,"Y");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>1038 && x<1088 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='y';
                }
                else if(x>1238 && x<1288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='x';
                }
                else
                {
                    outtextxy(915,450,"HATALI GIRIS");
                    outtextxy(970,496,"YAPTINIZ!");
                    outtextxy(930,643,"CIKMAK ICIN");
                    outtextxy(800,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(915,450,"HATALI GIRIS");
                outtextxy(970,496,"YAPTINIZ!");
                outtextxy(930,643,"CIKMAK ICIN");
                outtextxy(800,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else
        {
            outtextxy(915,450,"HATALI GIRIS");
            outtextxy(970,496,"YAPTINIZ!");
            outtextxy(930,643,"CIKMAK ICIN");
            outtextxy(800,689,"BIR TUSA BASINIZ!");
            getch();
            closegraph();
            return 0;
        }
        settextstyle(0,HORIZ_DIR,5);

        outtextxy(930,643,"CIKMAK ICIN");
        outtextxy(800,689,"BIR TUSA BASINIZ!");
        k=0;
    }
    else
    {
        setfillstyle(SOLID_FILL,15);
        bar(0,0,768,843);
        bar(0,0,1539,160);
        setcolor(12);
        settextstyle(0,HORIZ_DIR,5);
        outtextxy(1003,650,"2. HARITA");
        outtextxy(40,50,"GIRISLERI SECINIZ");
        outtextxy(38,170,"X");
        outtextxy(238,170,"Y");
        outtextxy(438,170,"Z");
        outtextxy(638,170,"T");

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(500);
        }
        getmouseclick(WM_LBUTTONDOWN,x, y);
        if(x>38 && x<88 && y>170 && y<220)/* x giris1*/
        {
            giris1='x';
            outtextxy(138,300,"Y");
            outtextxy(338,300,"Z");
            outtextxy(538,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>138 && x<188 && y>300 && y<350)/* y giris2*/
            {
                giris2='y';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Z");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='z';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>338 && x<388 && y>300 && y<350)/*z giris2*/
            {
                giris2='z';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Y");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='y';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else  if(x>538 && x<588 && y>300 && y<350)/*t giris 2*/
            {
                giris2='t';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Y");
                outtextxy(438,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='z';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='y';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(115,450,"HATALI GIRIS");
                outtextxy(170,496,"YAPTINIZ!");
                outtextxy(130,643,"CIKMAK ICIN");
                outtextxy(30,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>238 && x<288 && y>170 && y<220)/* y giris1*/
        {
            giris1='y';
            settextstyle(0,HORIZ_DIR,5);
            outtextxy(138,300,"X");
            outtextxy(338,300,"Z");
            outtextxy(538,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>138 && x<188 && y>300 && y<350)/*x giris2*/
            {
                giris2='x';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Z");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='z';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>338 && x<388 && y>300 && y<350)/*z giris2*/
            {
                giris2='z';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>538 && x<588 && y>300 && y<350)/*t giris2*/
            {
                giris2='t';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='z';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(115,450,"HATALI GIRIS");
                outtextxy(170,496,"YAPTINIZ!");
                outtextxy(130,643,"CIKMAK ICIN");
                outtextxy(30,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>438 && x<488 && y>170 && y<220)/*z giris1 */
        {
            giris1='z';
            settextstyle(0,HORIZ_DIR,5);
            outtextxy(138,300,"X");
            outtextxy(338,300,"Y");
            outtextxy(538,300,"T");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x, y);
            if(x>138 && x<188 && y>300 && y<350)/*x giris2*/
            {
                giris2='x';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Y");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='y';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>338 && x<388 && y>300 && y<350)/*y giris2*/
            {
                giris2='y';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"T");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='t';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*t cikis1*/
                {
                    cikis1='t';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>538 && x<588 && y>300 && y<350)/*t giris2*/
            {
                giris2='t';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"Y");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='y';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(115,450,"HATALI GIRIS");
                outtextxy(170,496,"YAPTINIZ!");
                outtextxy(130,643,"CIKMAK ICIN");
                outtextxy(30,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else if(x>638 && x<688 && y>170 && y<220)/*t giris1*/
        {
            giris1='t';
            outtextxy(138,300,"X");
            outtextxy(338,300,"Y");
            outtextxy(538,300,"Z");
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>138 && x<188 && y>300 && y<350)/* x giris2*/
            {
                giris2='x';
                bar(0,0,768,843);
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"Y");
                outtextxy(438,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='z';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='y';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>338 && x<388 && y>300 && y<350)/*y giris2*/
            {
                giris2='y';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"Z");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='z';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*z cikis1*/
                {
                    cikis1='z';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else if(x>538 && x<588 && y>300 && y<350)/*z giris 2*/
            {
                giris2='z';
                bar(0,0,768,843);
                settextstyle(0,HORIZ_DIR,5);
                outtextxy(30,50,"CIKISLARI GIRINIZ");
                outtextxy(238,270,"X");
                outtextxy(438,270,"Y");
                while(!ismouseclick(WM_LBUTTONDOWN))
                {
                    delay(500);
                }
                getmouseclick(WM_LBUTTONDOWN,x, y);
                if(x>238 && x<288 && y>270 && y<320)/*x cikis1*/
                {
                    cikis1='x';
                    cikis2='y';
                }
                else if(x>438 && x<488 && y>270 && y<320)/*y cikis1*/
                {
                    cikis1='y';
                    cikis2='x';
                }
                else
                {
                    outtextxy(115,450,"HATALI GIRIS");
                    outtextxy(170,496,"YAPTINIZ!");
                    outtextxy(130,643,"CIKMAK ICIN");
                    outtextxy(30,689,"BIR TUSA BASINIZ!");
                    getch();
                    closegraph();
                    return 0;
                }
            }
            else
            {
                outtextxy(115,450,"HATALI GIRIS");
                outtextxy(170,496,"YAPTINIZ!");
                outtextxy(130,643,"CIKMAK ICIN");
                outtextxy(30,689,"BIR TUSA BASINIZ!");
                getch();
                closegraph();
                return 0;
            }
        }
        else
        {
            outtextxy(115,450,"HATALI GIRIS");
            outtextxy(170,496,"YAPTINIZ!");
            outtextxy(130,643,"CIKMAK ICIN");
            outtextxy(30,689,"BIR TUSA BASINIZ!");
            getch();
            closegraph();
            return 0;

        }
        settextstyle(0,HORIZ_DIR,5);
        outtextxy(130,643,"CIKMAK ICIN");
        outtextxy(30,689,"BIR TUSA BASINIZ!");
        k=1;
    }
    getch();
    closegraph();

    if(k==1)//2. HARITA SECIIRSE
    {
        int *a;
        a=(int*)malloc(4*6*sizeof(int));
        printf("Giris 1: %c       Giris 2: %c\n",giris1,giris2);
        printf("Cikis 1: %c       Cikis 2: %c\n",cikis1,cikis2);
        printf("CADDELER ICIN ORTALAMA ARAC SAYISINI GIRINIZ(BILINMEYEN ICIN -1)\n");
        printf("x yolu : ");
        scanf("%d",(a+0*6+5));
        printf("\ny yolu : ");
        scanf("%d",(a+1*6+5));
        printf("\nz yolu : ");
        scanf("%d",(a+2*6+5));
        printf("\nt yolu : ");
        scanf("%d",(a+3*6+5));
        printf("\na caddesi : ");
        scanf("%d",(a+0*6+0));
        printf("\nb caddesi : ");
        scanf("%d",(a+0*6+1));
        printf("\nc caddesi : ");
        scanf("%d",(a+2*6+2));
        printf("\nd caddesi : ");
        scanf("%d",(a+1*6+3));
        printf("\ne caddesi : ");
        scanf("%d",(a+1*6+4));
        printf("=======================================================\n");
        for(i=0; i<4; i++)
        {
            for(j=0; j<6; j++)
            {
                printf("%d\t",*(a+i*6+j));
            }
            printf("\n");
        }
    }
    else//1. HARITA SECILIRSE
    {
        int *a;
        a=(int*)malloc(4*5*sizeof(int));
        printf("Giris 1: %c       Giris 2: %c\n",giris1,giris2);
        printf("Cikis 1: %c       Cikis 2: %c\n",cikis1,cikis2);
        printf("CADDELER ICIN ORTALAMA ARAC SAYISINI GIRINIZ(BILINMEYEN ICIN -1)\n");
        printf("x yolu : ");
        scanf("%d",(a+0*5+4));
        printf("\ny yolu : ");
        scanf("%d",(a+1*5+4));
        printf("\nz yolu : ");
        scanf("%d",(a+2*5+4));
        printf("\nt yolu : ");
        scanf("%d",(a+3*5+4));
        printf("\na caddesi : ");
        scanf("%d",(a+0*5+0));
        printf("\nb caddesi : ");
        scanf("%d",(a+0*5+1));
        printf("\nc caddesi : ");
        scanf("%d",(a+2*5+2));
        printf("\nd caddesi : ");
        scanf("%d",(a+1*5+3));
        printf("=======================================================\n");
        for(i=0; i<4; i++)
        {
            for(j=0; j<5; j++)
            {
                printf("%d\t",*(a+i*5+j));
            }
            printf("\n");
        }
    }

    return 0;
}
