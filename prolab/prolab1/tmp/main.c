#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>

typedef struct kayit{
	int ogrNo;
	int dersKodu;
	int puan;
} ky;

void sirala(int n)
{
	FILE *indexfp, *kayitfp;
	int i, j, r1, r2;
	ky s1, s2;

	indexfp = fopen("index.txt", "r+b");
	kayitfp = fopen("kayit.txt", "r+b");

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			fseek(kayitfp, sizeof(s1) * j, SEEK_SET);
			fseek(indexfp, sizeof(int) * j, SEEK_SET);

			fread(&r1, sizeof(int), 1, indexfp);

			fread(&r2, sizeof(int), 1, indexfp);

			if (r1 > r2)	//swap record and index
			{
				fread(&s1, sizeof(s1), 1, kayitfp);
				fread(&s2, sizeof(s2), 1, kayitfp);

				fseek(kayitfp, (sizeof(s1)) * j, SEEK_SET);
				fseek(indexfp, (sizeof(int)) * j, SEEK_SET);

				fwrite(&r2, sizeof(int), 1, indexfp);
				fwrite(&r1, sizeof(int), 1, indexfp);

				fwrite(&s2, sizeof(s1), 1, kayitfp);
				fwrite(&s1, sizeof(s1), 1, kayitfp);
			}
		}
	}

	fclose(indexfp);
	fclose(kayitfp);
}

void kayitEkle(ky *s1)
{
     printf("------------------------------------------------------------");
	int n = 0;
	float temp;
	FILE *indexfp, *kayitfp;

	indexfp = fopen("index.txt", "r+b");
	kayitfp = fopen("kayit.txt", "r+b");
    printf("------------------------------------------------------------");
	printf("\n\nOgrenci no giriniz: ");
	scanf("%d", &s1->ogrNo);
	printf("\nDers kodu giriniz: ");
	scanf("%d", &s1->dersKodu);
	printf("\nPuani giriniz: ");
	scanf("%d",	&s1->puan);

	fseek(kayitfp, 0, SEEK_END);

	if (fwrite(s1, sizeof(*s1), 1, kayitfp))
	{
		fseek(indexfp, 0, SEEK_END);
		fwrite(&(s1->ogrNo), sizeof(int), 1, indexfp);
	}
	else
	{
		printf("\n\nCould NOT add !!!");
	}
	rewind(indexfp);
	while ((fread(s1, sizeof(int), 1, indexfp)))
		n++;
    printf("\n-----------Kayit Eklendi-----------\n\n");
	fclose(indexfp);
	fclose(kayitfp);

	if (n > 1)
		sirala(n);
}

void kayitGuncelle(ky *s2, int r_n)
{
     printf("------------------------------------------------------------");
	int r, loc, flag = 0;
	float temp;
	FILE *indexfp, *kayitfp;

	indexfp = fopen("index.txt", "r+b");
	kayitfp = fopen("kayit.txt", "r+b");

	while (fread(&r, sizeof(int), 1, indexfp))
	{
		if (r == r_n)
		{
			flag = 1;

			break;
		}
	}
	if (!flag)
	{
		printf("\n\nKAYIT BULUNAMADI");
	}
	else
	{
		fseek(indexfp, (-1) * sizeof(int), SEEK_CUR);
		loc = ftell(indexfp);

		fseek(kayitfp, loc / sizeof(int) * sizeof(*s2), SEEK_SET);

		fread(s2, sizeof(*s2), 1, kayitfp);
        printf("------------------------------------------------------------");
		printf("\n\nogrNo :%d", s2->ogrNo);
		printf("\n\ndersKodu :%d", s2->dersKodu);
		printf("\n\npuan :%d", s2->puan);

		printf("\nYeni ders kodunu giriniz : ");
		scanf("%d", &(s2->dersKodu));
		printf("\nYeni puani giriniz : ");
		scanf("%d", &(s2->puan));

		fseek(kayitfp, (-1) * sizeof(*s2), SEEK_CUR);

		fwrite(s2, sizeof(*s2), 1, kayitfp);
	}

	printf("\n\n");
	fclose(indexfp);
	fclose(kayitfp);
}

void kayitBul(ky *s2, int r_n)
{
     printf("------------------------------------------------------------");
	int r, loc, flag = 0;

	FILE *indexfp, *kayitfp;

	indexfp = fopen("index.txt", "r+b");
	kayitfp = fopen("kayit.txt", "r+b");

	while (fread(&r, sizeof(int), 1, indexfp))
	{
		if (r == r_n)
		{
			flag = 1;

			break;
		}
	}

	if (!flag)
	{
		printf("\n\nKAYIT BULUNAMADI");
	}
	else
	{
		fseek(indexfp, (-1) * sizeof(int), SEEK_CUR);
		loc = ftell(indexfp);
		fseek(kayitfp, loc / sizeof(int) * sizeof(*s2), SEEK_SET);
		fread(s2, sizeof(*s2), 1, kayitfp);
        printf("------------------------------------------------------------");
		printf("\nogrNo\tdersKodu\tpuan");
		printf("\n%d\t%d\t\t%d",s2->ogrNo,s2->dersKodu,s2->puan);
	}

	printf("\n\n");
	fclose(indexfp);
	fclose(kayitfp);
}

void kayitSil(ky *s2, int r_n)
{
     printf("------------------------------------------------------------");
	int r, loc, flag = 0,file_handler_ind,file_handler_rec,file_size_ind,file_size_rec;
	char ch;

	FILE *indexfp, *kayitfp;

	indexfp = fopen("index.txt", "r+b");
	kayitfp = fopen("kayit.txt", "r+b");

	file_handler_ind=_fileno(indexfp);
	file_handler_rec=_fileno(kayitfp);

	file_size_ind=_filelength(file_handler_ind);
	file_size_rec=_filelength(file_handler_rec);

	while (fread(&r, sizeof(int), 1, indexfp))
	{
		if (r == r_n)
		{
			flag = 1;

			break;
		}
	}
	if (!flag)
	{
		printf("\n\nKAYIT BULUNAMADI");
	}
	else
	{
		fseek(indexfp, (-1) * sizeof(int), SEEK_CUR);
		loc = ftell(indexfp);

		fseek(kayitfp, loc / sizeof(int) * sizeof(*s2), SEEK_SET);
		fread(s2, sizeof(*s2), 1, kayitfp);

		printf("------------------------------------------------------------");
		printf("\n\nogrNo :%d", s2->ogrNo);
		printf("\n\ndersKodu :%d", s2->dersKodu);
		printf("\n\npuan :%d", s2->puan);

		printf("\n\nDosyayi silmek istediginizden emin misiniz? (e/h)");
		fflush(stdin);
		scanf("%c", &ch);

		if (ch == 'h' || ch == 'h')
			return;

		fseek(indexfp, sizeof(int), SEEK_CUR);	//  delete index value
		while (fread(&r, sizeof(int), 1, indexfp))
		{
			fseek(indexfp, (-2) * sizeof(int), SEEK_CUR);
			fwrite(&r, sizeof(int), 1, indexfp);
			fseek(indexfp, sizeof(int), SEEK_CUR);
		}

		while (fread(s2, sizeof(*s2), 1, kayitfp))
		{
			fseek(kayitfp, (-2) * sizeof(*s2), SEEK_CUR);
			fwrite(s2, sizeof(*s2), 1, kayitfp);
			fseek(kayitfp, sizeof(*s2), SEEK_CUR);
		}
	}

	_chsize(file_handler_ind,file_size_ind-sizeof(int));
	_chsize(file_handler_rec,file_size_rec-sizeof(*s2));

	printf("\n-----------Kayit Silindi-----------\n\n");
	fclose(indexfp);
	fclose(kayitfp);
}

void dosyaGoster(ky *s2){
     printf("------------------------------------------------------------");
	FILE *fp=NULL;
	int flag = 1, ch, r;

    printf("------------------------------------------------------------");
	printf("\n1:Indeks Dosyasini Goster\n2:Kayit Dosyasini Goster\nSeciminiz:");
	scanf("%d", &ch);

	switch (ch)
	{
		case 1:

			fp = fopen("index.txt", "rb");

			while (fread(&r, sizeof(int), 1, fp))
			{
				flag = 0;
				printf("\n%d", r);
			}

			break;

		case 2:

			fp = fopen("kayit.txt", "rb");

			while (fread(s2, sizeof(*s2), 1, fp))
			{
				if ((s2->ogrNo) != 0)
				{
					if (flag == 1)
						printf("\n\nogrNo\tdersKodu\tpuan");
					flag = 0;
					printf("\n\n%d", s2->ogrNo);
					printf("\t%d", s2->dersKodu);
					printf("\t\t%d", s2->puan);
				}
			}

			break;

		default:

			printf("\n\nGECERSIZ SECIM");
	}

	if (flag == 1)
		printf("\n\nKAYIT BULUNAMADI");
	printf("\n\n");
	fclose(fp);
}

void dosyaSil(){
     printf("------------------------------------------------------------");
    int ch;
    int sil;

    printf("------------------------------------------------------------");
	printf("\n1:Indeks Dosyasini Sil\n2:Kayit Dosyasini Sil\nSeciminiz:");
	scanf("%d", &ch);

    switch(ch){
        case 1:
            sil = remove("index.txt");

            if(sil == 0){
                fprintf(stdout,"-----------Indeks Dosyasi Silindi-----------\n\n");
            }
            else{
                fprintf(stderr,"-----------Indeks Dosyasi Bulunamadi-----------\n\n");
            }
        break;

        case 2:
            sil = remove("kayit.txt");
            if(sil == 0){
                fprintf(stdout,"-----------Kayit Dosyasi Silindi-----------\n\n");
            }
            else{
                fprintf(stderr,"-----------Kayit Dosyasi Bulunamadi-----------\n\n");
            }
        break;
    }


}

int main()
{
	FILE *fp;
	ky s1, s2;
	int choice, ogrNo_no;

	fp = fopen("kayit.txt", "a+b");
	fclose(fp);

	fp = fopen("index.txt", "a+b");
	fclose(fp);

	while (1)
	{
	    printf("------------------------------------------------------------");
		printf("\n1:Kayit Ekle\n2:Dosyayi Goster\n3:Kayit Bul\n4:Kayit Guncelle\n5:Kayit Sil\n6:Dosya Sil\n0:Cikis\n\nYapmak istediginiz islemi seciniz: \n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				kayitEkle(&s1);

				break;
			case 2:

				dosyaGoster(&s2);

				break;
			case 3:
			     printf("------------------------------------------------------------");
				printf("\n\nAramak istediginiz ogrenci noyu giriniz : ");
				scanf("%d", &ogrNo_no);
				kayitBul(&s2, ogrNo_no);

				break;
			case 4:
			     printf("------------------------------------------------------------");
				printf("\n\nDuzenlemek istediginiz ogrenci noyu giriniz : ");
				scanf("%d", &ogrNo_no);

				kayitGuncelle(&s2, ogrNo_no);

				break;
			case 5:
			     printf("------------------------------------------------------------");
				printf("\n\nSilmek istediginiz ogrenci noyu giriniz : ");
				scanf("%d", &ogrNo_no);

				kayitSil(&s2, ogrNo_no);

				break;

            case 6:

                dosyaSil();

                break;


			case 0:
				exit(0);

			default:
			     printf("------------------------------------------------------------");
				printf("\nGecersiz giris yaptiniz\n");
		}
	}

	return 0;
}
