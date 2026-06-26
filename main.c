#include <stdio.h>
#include <stdlib.h>
//ELANUR USSEN ECZANE OTOMASYONU

struct recete_bilgileri
{
    int numara;
    double recetefiyat;

};


typedef struct hasta_bilgileri
{
    char TC[12];
    char ad[20];
    char soyad[20];
    int yas;
    char cinsiyet[10];
    char yasadigi_yer[20];
    char telefon_no[12];
    float boy;
    float kilo;
    float indeks;
    struct recete_bilgileri *recete;
} hastabilgisi;

typedef struct ilac_bilgileri
{
    char ilac_adi[20];
    char ilac_firma[20];
    long int barkod;
    int stok;
    char son_kullanma_tarihi[11];
    float fiyat;
    char kullanim_amac[20];
} ilacbilgisi ;




int menu_fonksiyonu();
void hastakayit_fonksiyonu();
void hastalisteleme_fonksiyonu();
void ilackayit_fonksiyonu();
void ilaclisteleme_fonksiyonu();
void hastaarama_fonksiyonu();
void ilacarama_fonksiyonu();
void hastasilme_fonksiyonu();
void ilacsilme_fonksiyonu();
void hastaekleme_fonksiyonu();
void ilacekleme_fonksiyonu();
void guncelleme_fonksiyonu();
void satisyapma_fonksiyonu();
void satisbilgisi_fonksiyonu();
void hastauygunluktesti_fonksiyonu();
void recetefonk();


hastabilgisi *hasta;
ilacbilgisi *ilac;
struct recete_bilgileri *recete;
int hasta_sayisi=0,a=0,b=0;
int ilac_sayisi=0;
long int satilanilacbarkod=0;


int main()
{
    int secim=menu_fonksiyonu();
    while(secim!=0)
    {
        switch(secim)
        {
        case 1:
            hastaarama_fonksiyonu(hasta);
            break;
        case 2:
            hastakayit_fonksiyonu(hasta);
            break;
        case 3:
            hastasilme_fonksiyonu(hasta);
            break;
        case 4:
            hastaekleme_fonksiyonu(hasta);
            break;
        case 5:
            hastalisteleme_fonksiyonu(hasta);
            break;
        case 6:
            ilacarama_fonksiyonu(ilac);
            break;
        case 7:
            ilackayit_fonksiyonu(ilac);
            break;
        case 8:
            ilacsilme_fonksiyonu(ilac);
            break;
        case 9:
            ilacekleme_fonksiyonu(ilac);
            break;
        case 10:
            ilaclisteleme_fonksiyonu(ilac);
            break;
        case 11:
            hastauygunluktesti_fonksiyonu(hasta);

            break;
        case 12:
            satisbilgisi_fonksiyonu(ilac);
            break;
        case 13:
            guncelleme_fonksiyonu(hasta,ilac);
            break;
        case 14:
            satisyapma_fonksiyonu(ilac);
            break;
        case 15:
            recetefonk(recete,hasta);
            break;
        default:
            printf("\nHATALI BIR TUSLAMA ISLEMI YAPTINIZ TEKRAR DENEYINIZ LUTFEN :(");
            break;
        }
        secim=menu_fonksiyonu();
    }
    if (secim==0)
    {
        printf("\nPROGRAMDAN CIKIS ISLEMINIZ BASARIYLA GERCEKLESTIRILMISTIR!\n");
        free(hasta);
        free(ilac);
        free(recete);
        return 0;
    }
    return 0;
}


int menu_fonksiyonu() //1.FONKS
{
    int number=3,secim;
    char ascii=number;
    printf("\n\n%c~~~~~~~~~~~~~~~~ OZ YUNAK ECZANESINE HOSGELDINIZ ~~~~~~~~~~~~~~~~%c\n\n",ascii,ascii);
    printf("                  %c 1) HASTA ARAMA\n",ascii);
    printf("                  %c 2) HASTA KAYIT\n",ascii);
    printf("                  %c 3) HASTA SIL\n",ascii);
    printf("                  %c 4) HASTA EKLE\n",ascii);
    printf("                  %c 5) HASTA LISTESINI GORUNTULE\n\n",ascii);
    printf("                  %c 6) ILAC ARAMA\n",ascii);
    printf("                  %c 7) ILAC KAYIT\n",ascii);
    printf("                  %c 8) ILAC SIL\n",ascii);
    printf("                  %c 9) ILAC EKLE\n",ascii);
    printf("                  %c10) ILAC LISTESINI GORUNTULE\n\n",ascii);
    printf("                  %c11) HASTA SAGLIK UYGUNLUK TESTI\n",ascii);
    printf("                  %c12) SATIS BILGISI\n",ascii);
    printf("                  %c13) GUNCELLEME ISLEMLERI\n",ascii);
    printf("                  %c14) SATIS YAP\n",ascii);
    printf("                  %c15) RECETE BILGISI\n",ascii);
    printf("                  %c 0) PROGRAMDAN CIKIS\n",ascii);
    printf("\n%c~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%c\n\n",ascii,ascii);
    printf("\n\nLUTFEN YAPMAK ISTEDIGINIZ ISLEMI YUKARIDA BELIRTILEN NUMARALARDAN BIRINI TUSLAYARAK GERCEKLESTIRINIZ :) -->");
    scanf("%d",&secim);
    return secim;
}


void hastakayit_fonksiyonu()  //2.FONK
{
    int number=3,secim;
    char ascii=number;
    int hasta_sayisi2;
    printf("\nHASTA KAYIT ISLEMI BASLAMISTIR!\n");
    printf("KAC ADET HASTA KAYDEDILECEK LUTFEN BELIRTINIZ!: ");
    scanf("%d",&hasta_sayisi2);
    hasta_sayisi+=hasta_sayisi2;
    printf("\n");
    hasta = (struct hasta_bilgileri *)malloc(hasta_sayisi * sizeof(struct hasta_bilgileri));
    if (hasta == NULL)
    {
        printf("Bellek tahsisinde sorun olustu!");
        exit(1);
    }
    for (int i = 0; i < hasta_sayisi; i++)
    {
        printf("%d.HASTA TC:",i+1);
        scanf("%s",&(hasta+i)->TC);
        printf("%d.HASTA AD:",i+1);
        scanf("%s",(hasta+i)->ad);
        printf("%d.HASTA SOYAD:",i+1);
        scanf("%s",(hasta+i)->soyad);
        printf("%d.HASTA YASI:",i+1);
        scanf("%d",&(hasta+i)->yas);
        printf("%d.HASTA CINSIYET:",i+1);
        scanf("%s",(hasta+i)->cinsiyet);
        printf("%d.HASTANIN YASADIGI YER:",i+1);
        scanf("%s",(hasta+i)->yasadigi_yer);
        printf("%d.HASTA TELEFON NUMARASI:",i+1);
        scanf("%s",&(hasta+i)->telefon_no);
        printf("\n\n");
    }
    printf("HASTA KAYIT ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("-----------------------------------------------%c\n\n",ascii);
}

void hastalisteleme_fonksiyonu()  //3.FONKS
{
    int number = 3;
    char ascii = number;

    if (hasta == NULL)
    {
        printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR LUTFEN HASTA KAYIT ISLEMINIZI YAPINIZ!\n");
        return;
    }

    printf("HASTA LISTELEME ISLEMINIZ BASLAMISTIR!");
    printf("\nHASTA LISTESI OLUSTURULUYOR.....\n\n");

    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "HASTA NO", "TC", "AD", "SOYAD", "YAS", "CINSIYET", "YASADIGI YER", "TELEFON NO");

    for (int i = 0; i < hasta_sayisi; i++)
    {
        printf("%-20d%-20s%-20s%-20s%-20d%-20s%-20s%-20s\n", i + 1, (hasta + i)->TC, (hasta + i)->ad, (hasta + i)->soyad,
               (hasta + i)->yas, (hasta + i)->cinsiyet, (hasta + i)->yasadigi_yer, (hasta + i)->telefon_no);
        printf("\n");
    }

    printf("\nHASTA LISTELEME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("---------------------------------------------------%c\n\n", ascii);
}


void ilackayit_fonksiyonu()  //4.FONKS
{
    int number=3,secim;
    char ascii=number;
    int ilac_sayisi2;
    printf("\ILAC KAYIT ISLEMI BASLAMISTIR!\n");
    printf("KAC ADET ILAC KAYDEDILECEK LUTFEN BELIRTINIZ!: ");
    scanf("%d",&ilac_sayisi2);
    ilac_sayisi+=ilac_sayisi2;
    printf("\n");
    ilac = (struct ilac_bilgileri *)malloc(ilac_sayisi * sizeof(struct ilac_bilgileri));
    if (ilac == NULL)
    {
        printf("Bellek tahsisinde sorun olustu!");
        exit(1);
    }
    for (int i = 0; i < ilac_sayisi; i++)
    {
        printf("%d.ILACIN ADI:",i+1);
        scanf("%s",(ilac+i)->ilac_adi);
        printf("%d.ILACIN AIT OLDUGU FIRMA ADI:",i+1);
        scanf("%s",(ilac+i)->ilac_firma);
        printf("%d.ILACIN BARKODU:",i+1);
        scanf("%ld",&(ilac+i)->barkod);
        printf("%d.ILACIN STOK SAYISI:",i+1);
        scanf("%d",&(ilac+i)->stok);
        printf("%d.ILACIN SON KULLANMA TARIHI:",i+1);
        scanf("%s",(ilac+i)->son_kullanma_tarihi);
        printf("%d.ILACIN FIYATI:",i+1);
        scanf("%f",&(ilac+i)->fiyat);
        printf("%d.ILACIN KULLANIM AMACI(TEDAVI/ANTIBIYOTIK/DIGER):",i+1);
        scanf("%s",(ilac+i)->kullanim_amac);
        printf("\n");
    }
    printf("ILAC KAYIT ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("-----------------------------------------------%c\n\n",ascii);
}


void ilaclisteleme_fonksiyonu()  //5.FONKS
{
    int number = 3;
    char ascii = number;

    if (ilac == NULL)
    {
        printf("\nHENUZ ILAC KAYDI GIRISINIZ BULUNMAMAKTADIR LUTFEN ILAC KAYIT ISLEMINIZI YAPINIZ!\n");
        return;
    }

    printf("ILAC LISTELEME ISLEMINIZ BASLAMISTIR!");
    printf("\nILAC LISTESI:\n\n");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "ILAC NO", "ILAC ADI", "ILAC FIRMA ADI", "BARKOD", "STOK", "SKT", "FIYAT", "KULLANIM AMACI");

    for (int i = 0; i < ilac_sayisi; i++)
    {
        printf("%-20d%-20s%-20s%-20ld%-20d%-20s%-20.2fTL%-20s\n", i + 1, (ilac + i)->ilac_adi, (ilac + i)->ilac_firma,
               (ilac + i)->barkod, (ilac + i)->stok, (ilac + i)->son_kullanma_tarihi, (ilac + i)->fiyat, (ilac + i)->kullanim_amac);
        printf("\n");
    }

    printf("\nILAC LISTELEME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("---------------------------------------------------%c\n\n", ascii);
}


void hastaarama_fonksiyonu() //6.FONK
{
    int number=3,secim;
    char ascii=number;
    int belirtec=0;
    char tcarama[12];
    printf("ARADIGINIZ KISININ TC NUMARASINI GIRINIZ: ");
    scanf("%s",&tcarama);
    if (hasta == NULL)
    {
        printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR LUTFEN HASTA KAYIT ISLEMINIZI YAPINIZ!\n");
        return;
    }
    for (int i=0; i<hasta_sayisi; i++)
    {
        if (strcmp((hasta+i)->TC, tcarama) == 0)

        {
            printf("\n\nTC ILE UYUSAN HASTA BULUNDU,BILGILER YAZDIRILIYOR....\n");
            printf("TC: %s\n", (hasta + i)->TC);
            printf("AD: %s\n", (hasta + i)->ad);
            printf("SOYAD: %s\n", (hasta + i)->soyad);
            printf("YAS: %d\n", (hasta + i)->yas);
            printf("CINSIYET: %s\n", (hasta + i)->cinsiyet);
            printf("YASADIGI YER: %s\n", (hasta + i)->yasadigi_yer);
            printf("TELEFON NUMARASI: %s\n", (hasta + i)->telefon_no);
            printf("\n\n");
            printf("HASTA ARAMA ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
            printf("---------------------------------------------------%c\n\n",ascii);
            belirtec=1;
            break;
        }
    }
    if (belirtec==0)
    {
        printf("\nYAZILAN TC ILE UYUSAN HERHANGI BIR HASTA MEVCUT DEGILDIR\n");
    }

}


void ilacarama_fonksiyonu()  //7.FONKS
{
    int number=3,secim;
    char ascii=number;
    int belirtec=0;
    long int barkodarama;
    printf("ARADIGINIZ ILACIN BARKOD NUMARASINI GIRINIZ: ");
    scanf("%ld",&barkodarama);
    if (ilac == NULL)
    {
        printf("HENUZ ILAC KAYDI GIRISINIZ BULUNMAMAKTADIR LUTFEN ILAC KAYIT ISLEMINIZI YAPINIZ!\n");
        return;
    }
    for (int i=0; i<ilac_sayisi; i++)
    {
        if ((ilac+i)->barkod==barkodarama)

        {
            printf("\n\BARKOD ILE UYUSAN ILAC BULUNDU,BILGILER YAZDIRILIYOR....\n");
            printf("ILAC ADI %s:\n",(ilac + i)->ilac_adi );
            printf("ILAC FIRMASI: %s\n",(ilac + i)->ilac_firma);
            printf("ILACIN BARKODU: %ld\n", (ilac + i)->barkod);
            printf("ILACIN STOK SAYISI: %d\n", (ilac + i)->stok);
            printf("ILACIN SON KULLANMA TARIHI: %s\n", (ilac + i)->son_kullanma_tarihi);
            printf("ILACIN FIYATI: %.2f\n", (ilac + i)->fiyat);
            printf("ILACIN KULLANIM AMACI (TEDAVI/ANTIBIYOTIK/DIGER): %s\n", (ilac + i)->kullanim_amac);
            printf("\n\n");
            printf("ILAC ARAMA ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
            printf("---------------------------------------------------%c\n\n",ascii);
            belirtec=1;
            break;
        }
    }
    if (belirtec==0)
    {
        printf("\nYAZILAN BARKOD ILE UYUSAN HERHANGI BIR ILAC KAYDI MEVCUT DEGILDIR\n");
    }

}


void hastasilme_fonksiyonu()  //8.FONKS
{

    int number=3,secim;
    char ascii=number;
    int belirtec = 0;
    char TCsilme[12];

    if (hasta == NULL)
    {
        printf("\nHASTA KAYDI BULUNMAMAKTADIR, LUTFEN HASTA KAYDI EKLEYINIZ VE TEKRAR DENEYINIZ!\n");
        return;
    }

    printf("\nHASTA SILME ISLEMI BASLAMISTIR!");
    printf("\nSILMEK ISTEDIGINIZ HASTANIN TC NUMARASINI GIRINIZ: ");
    scanf("%s",&TCsilme);

    for (int i = 0; i < hasta_sayisi; i++)
    {
        if (strcmp((hasta + i)->TC,TCsilme) == 0)
        {
            printf("\nSILINEN HASTANIN BILGILERI:\n");
            printf("TC: %s\n", (hasta + i)->TC);
            printf("AD: %s\n", (hasta + i)->ad);
            printf("SOYAD: %s\n", (hasta + i)->soyad);
            printf("YAS: %d\n", (hasta + i)->yas);
            printf("CINSIYET: %s\n", (hasta + i)->cinsiyet);
            printf("YASADIGI YER: %s\n", (hasta + i)->yasadigi_yer);
            printf("TELEFON NUMARASI: %s\n", (hasta + i)->telefon_no);
            for (int j = i; j < hasta_sayisi - 1; j++)
            {
                strcpy((hasta + j)->TC, (hasta + j + 1)->TC);
                strcpy((hasta + j)->ad, (hasta + j + 1)->ad);
                strcpy((hasta + j)->soyad, (hasta + j + 1)->soyad);
                (hasta + j)->yas = (hasta + j + 1)->yas;
                strcpy((hasta + j)->cinsiyet, (hasta + j + 1)->cinsiyet);
                strcpy((hasta + j)->yasadigi_yer, (hasta + j + 1)->yasadigi_yer);
                strcpy((hasta + j)->telefon_no, (hasta + j + 1)->telefon_no);
            }
            hasta = realloc(hasta, hasta_sayisi * sizeof(struct hasta_bilgileri));
            printf("HASTA SILME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
            printf("---------------------------------------------------%c\n\n",ascii);
            belirtec = 1;
            hasta_sayisi--;
            break;
        }
    }

    if (belirtec == 0)
    {
        printf("\nYAZILAN TC ILE UYUSAN HERHANGI BIR HASTA MEVCUT DEGILDIR MAALESEF:( \n");
    }

}



void ilacsilme_fonksiyonu() //9.FONKS
{
    int number = 3;
    char ascii = number;
    int belirtec = 0;
    long int barkod_silme;

    if (ilac == NULL)
    {
        printf("\nILAC KAYDI BULUNMAMAKTADIR, LUTFEN ILAC KAYDI EKLEYINIZ VE TEKRAR DENEYINIZ!\n");
        return;
    }

    printf("\nILAC SILME ISLEMI BASLAMISTIR!");
    printf("\nSILMEK ISTEDIGINIZ ILACIN BARKOD NUMARASINI GIRINIZ: ");
    scanf("%ld", &barkod_silme);

    for (int i = 0; i < ilac_sayisi; i++)
    {
        if ((ilac + i)->barkod == barkod_silme)
        {
            printf("\nSILINEN ILACIN BILGILERI:\n");
            printf("ILAC ADI: %s\n", (ilac + i)->ilac_adi);
            printf("ILAC FIRMASI: %s\n", (ilac + i)->ilac_firma);
            printf("ILACIN BARKODU: %ld\n", (ilac + i)->barkod);
            printf("ILACIN STOK SAYISI: %d\n", (ilac + i)->stok);
            printf("ILACIN SON KULLANMA TARIHI: %s\n", (ilac + i)->son_kullanma_tarihi);
            printf("ILACIN FIYATI: %.2f\n", (ilac + i)->fiyat);
            printf("ILACIN KULLANIM AMACI (TEDAVI/ANTIBIYOTIK/DIGER): %s\n", (ilac + i)->kullanim_amac);
            for (int j = i; j < ilac_sayisi - 1; j++)
            {
                strcpy((ilac + j)->ilac_adi, (ilac + j + 1)->ilac_adi);
                strcpy((ilac + j)->ilac_firma, (ilac + j + 1)->ilac_firma);
                (ilac + j)->barkod = (ilac + j + 1)->barkod;
                (ilac + j)->stok = (ilac + j + 1)->stok;
                strcpy((ilac + j)->son_kullanma_tarihi, (ilac + j + 1)->son_kullanma_tarihi);
                (ilac + j)->fiyat = (ilac + j + 1)->fiyat;
                strcpy((ilac + j)->kullanim_amac, (ilac + j + 1)->kullanim_amac);
            }
            ilac = realloc(ilac, (ilac_sayisi - 1) * sizeof(struct ilac_bilgileri));
            printf("\nILAC SILME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
            printf("---------------------------------------------------%c\n\n", ascii);
            belirtec = 1;
            ilac_sayisi--;
            break;
        }
    }

    if (belirtec == 0)
    {
        printf("\nYAZILAN BARKODA UYAN HERHANGI BIR ILAC MEVCUT DEGILDIR MAALESEF:( \n");
    }
}


void hastaekleme_fonksiyonu() //10.FONKS
{
    int number = 3;
    char ascii = number;
    int hasta_sayisi2;

    printf("\nHASTA EKLEME ISLEMI BASLAMISTIR!\n");
    printf("KAC ADET HASTA EKLENECEK LUTFEN BELIRTINIZ: ");
    scanf("%d", &hasta_sayisi2);
    hasta_sayisi += hasta_sayisi2;
    hasta = (struct hasta_bilgileri *)realloc(hasta, hasta_sayisi * sizeof(struct hasta_bilgileri));

    if (hasta == NULL)
    {
        printf("Bellek tahsisinde sorun olustu!");
        exit(1);
    }
    for (int i = hasta_sayisi - hasta_sayisi2; i < hasta_sayisi; i++)
    {
        printf("%d.HASTA TC:", i + 1);
        scanf("%s", (hasta + i)->TC);
        printf("%d.HASTA AD:", i + 1);
        scanf("%s", (hasta + i)->ad);
        printf("%d.HASTA SOYAD:", i + 1);
        scanf("%s", (hasta + i)->soyad);
        printf("%d.HASTA YASI:", i + 1);
        scanf("%d", &(hasta + i)->yas);
        printf("%d.HASTA CINSIYET:", i + 1);
        scanf("%s", (hasta + i)->cinsiyet);
        printf("%d.HASTANIN YASADIGI YER:", i + 1);
        scanf("%s", (hasta + i)->yasadigi_yer);
        printf("%d.HASTA TELEFON NUMARASI:", i + 1);
        scanf("%s", &(hasta + i)->telefon_no);
        printf("\n");
    }

    printf("HASTA EKLEME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("-----------------------------------------------%c\n\n", ascii);
}

void ilacekleme_fonksiyonu()  //11.FONKS
{
    int number = 3;
    char ascii = number;
    int ilac_sayisi2;

    printf("\nILAC EKLEME ISLEMI BASLAMISTIR!\n");
    printf("KAC ADET ILAC EKLENECEK LUTFEN BELIRTINIZ: ");
    scanf("%d", &ilac_sayisi2);
    ilac_sayisi += ilac_sayisi2;
    ilac = (struct ilac_bilgileri *)realloc(ilac, ilac_sayisi * sizeof(struct ilac_bilgileri));

    if (ilac == NULL)
    {
        printf("Bellek tahsisinde sorun olustu!");
        exit(1);
    }
    for (int i = ilac_sayisi - ilac_sayisi2; i < ilac_sayisi; i++)
    {
        printf("%d.ILACIN ADI:", i + 1);
        scanf("%s", (ilac + i)->ilac_adi);
        printf("%d.ILACIN AIT OLDUGU FIRMA ADI:", i + 1);
        scanf("%s", (ilac + i)->ilac_firma);
        printf("%d.ILACIN BARKODU:", i + 1);
        scanf("%ld", &(ilac + i)->barkod);
        printf("%d.ILACIN STOK SAYISI:", i + 1);
        scanf("%d", &(ilac + i)->stok);
        printf("%d.ILACIN SON KULLANMA TARIHI:", i + 1);
        scanf("%s", (ilac + i)->son_kullanma_tarihi);
        printf("%d.ILACIN FIYATI:", i + 1);
        scanf("%f", &(ilac + i)->fiyat);
        printf("%d.ILACIN KULLANIM AMACI(TEDAVI/ANTIBIYOTIK/DIGER):", i + 1);
        scanf("%s", (ilac + i)->kullanim_amac);
        printf("\n");
    }

    printf("ILAC EKLEME ISLEMINIZ BASARIYLA SONLANMISTIR!\n");
    printf("-----------------------------------------------%c\n\n", ascii);
}


void guncelleme_fonksiyonu()  //12.FONKS
{
    int number = 3;
    char ascii = number;
    int secim;
    printf("HASTA GUNCELLEMESI ICIN 1'I ILAC GUNCELLEMESI ICIN 2'YI TUSLAYINIZ!:");
    scanf("%d",&secim);
    printf("\n");
    if (secim==1)
    {
        printf("HASTA BILGILERINI GUNCELLEYECEKSINIZ :)\n");
        if (hasta == NULL)
        {
            printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR. LUTFEN KAYIT EKLEYINIZ!\n");
            return;
        }
        char hastatc[12];
        printf("\nGUNCELLEME ISLEMI YAPILACAK OLAN HASTANIN TC'SINI GIRINIZ: ");
        scanf("%s", &hastatc);
        printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "HASTA NO", "TC", "AD", "SOYAD", "YAS", "CINSIYET", "YASADIGI YER", "TELEFON NO");

        for (int i = 0; i < hasta_sayisi; i++)
        {
            if (strcmp((hasta+i)->TC, hastatc) == 0)
            {
                printf("%-20d%-20s%-20s%-20s%-20d%-20s%-20s%-20s\n", i + 1, (hasta + i)->TC, (hasta + i)->ad, (hasta + i)->soyad,
                       (hasta + i)->yas, (hasta + i)->cinsiyet, (hasta + i)->yasadigi_yer, (hasta + i)->telefon_no);
                printf("\n");
            }

        }
        int secim2;
        printf("GUNCELLEMEK ISTEDIGINIZ BILGI ICIN GEREKLI NUMARALARI TUSLAYINIZ: ");
        printf("\n%c1. AD\n%c2. SOYAD\n%c3. YAS\n%c4. CINSIYET\n%c5. YASADIGI YER\n%c6. TELEFON NUMARASI\n\n",ascii,ascii,ascii,ascii,ascii,ascii);
        scanf("%d", &secim2);

        switch (secim2)
        {
        case 1:
            printf("YENI AD: ");
            scanf("%s", hasta->ad);
            break;
        case 2:
            printf("YENI SOYAD: ");
            scanf("%s", hasta->soyad);
            break;
        case 3:
            printf("YENI YAS: ");
            scanf("%d", &(hasta->yas));
            break;
        case 4:
            printf("YENI CINSIYET: ");
            scanf("%s", hasta->cinsiyet);
            break;
        case 5:
            printf("YENI YASADIGI YER: ");
            scanf("%s", hasta->yasadigi_yer);
            break;
        case 6:
            printf("YENI TELEFON NUMARASI: ");
            scanf("%s", hasta->telefon_no);
            break;
        default:
            printf("YANLIS TUSLAMA YAPTINIZ!\n");
            return;
        }

        printf("\nHASTA BILGILERI GUNCELLENMISTIR :)\n");
    }
    else
    {
        printf("ILAC BILGILERINI GUNCELLEYECEKSINIZ :)\n");
        if (ilac == NULL)
        {
            printf("\nHENUZ ILAC KAYDI GIRISINIZ BULUNMAMAKTADIR. LUTFEN KAYIT EKLEYINIZ!\n");
            return;
        }
        long int barkodilac;
        printf("\nGUNCELLEME ISLEMI YAPILACAK OLAN ILACIN BARKODUNU GIRINIZ: ");
        scanf("%ld", &barkodilac);
        printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "ILAC NO", "ILAC ADI", "ILAC FIRMA ADI", "BARKOD", "STOK", "SKT", "FIYAT", "KULLANIM AMACI");
        for (int i = 0; i < ilac_sayisi; i++)
        {
            if ((ilac + i)->barkod == barkodilac)
            {
                printf("%-20d%-20s%-20s%-20ld%-20d%-20s%-20.2fTL%-20s\n", i + 1, (ilac + i)->ilac_adi, (ilac + i)->ilac_firma,
                       (ilac + i)->barkod, (ilac + i)->stok, (ilac + i)->son_kullanma_tarihi, (ilac + i)->fiyat, (ilac + i)->kullanim_amac);
                printf("\n");
            }
        }
        int secim2;
        printf("\n%c1. ILACIN ADI\n%c2. ILACIN FIRMASI\n%c3. BARKOD\n%c4. STOK SAYISI\n%c5. SON KULLANMA TARIHI\n%c6. FIYAT\n%c7.KULLANIM AMACI\n\n",ascii,ascii,ascii,ascii,ascii,ascii,ascii);
        printf("GUNCELLEMEK ISTEDIGINIZ BILGI ICIN GEREKLI NUMARALARI TUSLAYINIZ:");
        scanf("%d", &secim2);
        switch (secim2)
        {
        case 1:
            printf("YENI AD: ");
            scanf("%s", (ilac->ilac_adi));
            break;
        case 2:
            printf("YENI FIRMA: ");
            scanf("%s", (ilac->ilac_firma));
            break;
        case 3:
            printf("YENI BARKOD: ");
            scanf("%ld", &(ilac->barkod));
            break;
        case 4:
            printf("YENI STOK SAYISI: ");
            scanf("%d",& (ilac->stok));
            break;
        case 5:
            printf("YENI SON KULLANMA TARIHI: ");
            scanf("%s", (ilac->son_kullanma_tarihi));
            break;
        case 6:
            printf("YENI FIYAT: ");
            scanf("%f", &(ilac->fiyat));
            break;
        case 7:
            printf("YENI KULLANIM AMACI: ");
            scanf("%s", (ilac->kullanim_amac));
            break;
        default:
            printf("YANLIS TUSLAMA YAPTINIZ!\n");
            return;

        }
    }
}

void satisyapma_fonksiyonu() //13.FONKS
{
    satilanilacbarkod=0;
    int number = 3;
    char ascii = number;
    if (hasta==NULL)
    {
        printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR. LUTFEN HASTA KAYIT ISLEMINIZI YAPINIZ!\n");
    }

    if (ilac == NULL)
    {
        printf("\nHENUZ ILAC KAYDI GIRISINIZ BULUNMAMAKTADIR. LUTFEN ILAC KAYIT ISLEMINIZI YAPINIZ!\n");
        return;
    }

    printf("\nSATIS YAPMA ISLEMI BASLAMISTIR...");
    printf("\n\nSATIS YAPMAK ISTEDIGINIZ ILACIN BARKOD NUMARASINI GIRINIZ: ");
    long int barkodsatis;
    scanf("%ld", &barkodsatis);

    int satisno= -1;

    for (int i = 0; i < ilac_sayisi; i++)
    {
        if ((ilac + i)->barkod == barkodsatis)
        {
            satisno= i;
            break;
        }
    }

    if (satisno == -1)
    {
        printf("\nGIRILEN BARKOD NUMARASINA UYAN ILAC BULUNAMADI. LUTFEN BARKOD NUMARASINI KONTROL EDINIZ!\n");
        return;
    }

    printf("\n----------------SATIS YAPILACAK ILAC BILGILERI--------------\n");
    printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "ILAC NO", "ILAC ADI", "ILAC FIRMA ADI", "BARKOD", "STOK", "SKT", "FIYAT", "KULLANIM AMACI");
    for (int i = 0; i < ilac_sayisi; i++)
    {
        if ((ilac + i)->barkod == barkodsatis)
        {
            printf("%-20d%-20s%-20s%-20ld%-20d%-20s%-20.2f%-20s\n", i + 1, (ilac +satisno )->ilac_adi, (ilac +satisno )->ilac_firma,
                   (ilac + satisno)->barkod, (ilac + satisno)->stok, (ilac + satisno)->son_kullanma_tarihi, (ilac + satisno)->fiyat, (ilac + satisno)->kullanim_amac);
            printf("\n");
        }
    }

    printf("\n\nKAC ADET SATIS YAPILACAK?: ");
    int satisadet;
    scanf("%d", &satisadet);

    if (satisadet <= 0)
    {
        printf("\nGECERSIZ ADET GIRILDIGI ICIN SATIS YAPILAMAZ!\n");
        return;
    }

    if ((ilac + satisno)->stok < satisadet)
    {
        printf("\nSTOKTA YETERLI MIKTARDA ILAC BULUNMAMAKTADIR. LUTFEN STOK DURUMUNU KONTROL EDINIZ!\n");
        return;
    }

    float toplam_tutar = (ilac + satisno)->fiyat * satisadet;

    printf("\nTOPLAM SATIS TUTARI: %.2f TL\n", toplam_tutar);

    printf("\n1. NAKIT\n2. KREDI KARTI\n3. BANKA HAVALE/EFT\n");
    printf("\nODEME ISLEMI ICIN SECIM YAPINIZ:");
    int odeme_secim;
    scanf("%d", &odeme_secim);

    switch (odeme_secim)
    {
    case 1:
        printf("\nNAKIT ODEME ALINMISTIR. IYI GUNLER DILERIZ :)\n");
        break;
    case 2:
        printf("\nKREDI KARTI ODEME ALINMISTIR. IYI GUNLER DILERIZ :)\n");
        break;
    case 3:
        printf("\nBANKA HAVALE/EFT ODEME ALINMISTIR. IYI GUNLER DILERIZ :)\n");
        break;
    default:
        printf("\nYANLIS TUSLAMA YAPTINIZ!\n");
        return;
    }

    (ilac + satisno)->stok -= satisadet;

    printf("\nSATIS ISLEMI BASARIYLA TAMAMLANMISTIR. IYI GUNLER DILERIZ :)\n");
    satilanilacbarkod+=barkodsatis;
    a+=satisno;
    b+=satisadet;

}



void satisbilgisi_fonksiyonu() //14.FONKS
{
    printf("SATILAN ILACLAR HAKKINDA BILGILER ASAGIDA YER ALMAKTADIRLAR\n--------------------------------------------------------------\n\n");
    printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "ILAC NO", "ILAC ADI", "ILAC FIRMA ADI", "BARKOD", "KAC ADET SATILDI", "SKT", "FIYAT", "KULLANIM AMACI");
    for (int i=0; i<ilac_sayisi; i++)
    {
        if ((ilac+i)->barkod==satilanilacbarkod)
        {

            printf("%-20d%-20s%-20s%-20ld%-20d%-20s%-20.2f%-20s\n", i + 1, (ilac +a )->ilac_adi, (ilac +a )->ilac_firma,
                   (ilac + a)->barkod, b, (ilac + a)->son_kullanma_tarihi, (ilac + a)->fiyat, (ilac + a)->kullanim_amac);
            printf("\n");

        }
    }
}

void hastauygunluktesti_fonksiyonu() // 15.FONKS
{
    int number = 3;
    char ascii = number;
    char tcsorgulama[12];

    printf("VUCUT KITLE INDEKSINIZ HESAPLANACAK LUTFEN BILGILERI OLABILDIGINCE DOGRU GIRINIZ...\n\n");
    printf("BEDEN KITLE INDEKSI SADECE KAYITLI HASTALARIMIZA UYGULANABILMEKTEDIR!\n\n");
    printf("HESAPLAMA YAPILACAK HASTANIN TC NUMARASINI GIREREK YARDIMCI OLUN BU ISLEMIN YSPILMASINA:");
    scanf("%s", tcsorgulama);

    if (hasta == NULL)
    {
        printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR LUTFEN HASTA KAYIT ISLEMINIZI YAPINIZ!\n\n");
        return;
    }

    int hastaBulundu = 0;

    for (int i = 0; i < hasta_sayisi; i++)
    {
        if (strcmp((hasta + i)->TC, tcsorgulama) == 0)
        {
            hastaBulundu = 1;

            printf("HASTA BULUNDU ISLEMINIZ DEVAM EDIYOR...\n");
            printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "HASTA NO", "TC", "AD", "SOYAD", "YAS", "CINSIYET", "YASADIGI YER", "TELEFON NO");
            printf("%-20d%-20s%-20s%-20s%-20d%-20s%-20s%-20s\n", i + 1, (hasta + i)->TC, (hasta + i)->ad, (hasta + i)->soyad,
                   (hasta + i)->yas, (hasta + i)->cinsiyet, (hasta + i)->yasadigi_yer, (hasta + i)->telefon_no);

            printf("HASTANIN BOYUNU GIRINIZ:");
            scanf("%f", &(hasta + i)->boy);

            printf("HASTANIN KILOSUNU GIRINIZ:");
            scanf("%f", &(hasta + i)->kilo);

            printf("HASTAYA AIT YENI BILGILER\n");
            printf("%-20s%-20s\n", "BOY", "KILO");
            printf("%-20f%-20f\n\n", (hasta + i)->boy, (hasta + i)->kilo);

            float vucutKitleIndeksi = ((hasta + i)->kilo) / ((((hasta + i)->boy)*0.01) * (((hasta + i)->boy)*0.01));
            printf("VUCUT KITLE INDEKSINIZ: %.2f\n",vucutKitleIndeksi);

            if (vucutKitleIndeksi < 18.5)
            {
                printf("IDEAL KILO ALTINDASINIZ\n");
            }
            else if (vucutKitleIndeksi >= 18.5 && vucutKitleIndeksi < 24.9)
            {
                printf("IDEAL KILODASINIZ\n");
            }
            else if (vucutKitleIndeksi >= 25 && vucutKitleIndeksi < 30)
            {
                printf("IDEAL KILO UZERINDESINIZ\n");
            }
            else if (vucutKitleIndeksi >= 30 && vucutKitleIndeksi < 40)
            {
                printf("IDEAL KILOUNUN COK USTUNDESINIZ\n");
            }
            else
            {
                printf("OBEZLIK\n");
            }

            return 0;
        }
        if (!hastaBulundu)
        {
            printf("TC ILE ESLESEN HASTA KAYDI BULUNMAMAKTADIR!\n");
            break;
        }
    }

}

void recetefonk()  //16.FONKS
{
    int recetesayisi=1;

    char hastatc[12];
    printf("\RECETELEME ISLEMI YAPILACAK OLAN HASTANIN TC'SINI GIRINIZ: ");
    scanf("%s", &hastatc);
    if (hasta == NULL)
    {
        printf("\nHENUZ HASTA KAYDI GIRISINIZ BULUNMAMAKTADIR. LUTFEN KAYIT EKLEYINIZ!\n");
        return;
    }

    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n", "HASTA NO", "TC", "AD", "SOYAD", "YAS", "CINSIYET", "YASADIGI YER", "TELEFON NO");

    for (int i = 0; i < hasta_sayisi; i++)
    {
        (hasta+i)->recete = (struct recete_bilgileri*)malloc(sizeof(struct recete_bilgileri)*recetesayisi);
        printf("%-20d%-20s%-20s%-20s%-20d%-20s%-20s%-20s\n", i + 1, (hasta + i)->TC, (hasta + i)->ad, (hasta + i)->soyad,
               (hasta + i)->yas, (hasta + i)->cinsiyet, (hasta + i)->yasadigi_yer, (hasta + i)->telefon_no);
        printf("\n");
        printf("RECETE BILGILERI:\n");
        printf("RECETE NUMARASI: ");
        scanf("%d", &((hasta+i)->recete)->numara);
        printf("RECETE FIYAT: ");
        scanf("%lf", &((hasta+i)->recete)->recetefiyat);

        printf("%-20s%-20s%-20s%\n", "RECETE NO", "TC","RECETE FIYAT");
        printf("%-20d%-20s%-20.2lf\n", ((hasta+i)->recete)->numara, hastatc,((hasta+i)->recete)->recetefiyat);

        printf("RECETE IPTAL KONUMDADIR");
        break;
    }

}
