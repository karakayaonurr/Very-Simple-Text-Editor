///C'DEKI STANDART GIRIS/CIKIS KUTUPHANESI
#include<stdio.h>
///KISMI OLARAK MATEMATIKSEL ISLEMLER KUTUPHANESI
#include<stdlib.h>
///DOS DESTEKLI GIRIS/CIKIS KUTUPHANESI
#include<conio.h>
///STRING KUTUPHANESI
#include<string.h>
///DOSYA DEGISKENLERI OLUSTURUR
FILE *dosya1,*dosya2;
///KARAKTER (DIZISI) DEGISTEKLERI OLUSTURUR
char dosyaadi[10],c;
///SAYISAL DEGISKEN OLUSTURUR
int secim;
///EDITOR FONKSIYONU
void Editor(){
    ctrln:
    ///ARAC CUBUGU BASLANGICI
    system("cls");
    printf("\t\t********** Metin Editoru (Notepad) **********\n\n");
    printf("Yeni: Ctrl+N\tAc: Ctrl+O\tKaydet: Ctrl+S");
    printf("\n-------------------------------------------------------------------------------\n");
    ///ARAC CUBUGU BITISI
    ///'w' ILE DOSYA OLSUN-OLMASIN YENI DOSYA ACILIR
    dosya1=fopen("GeciciSayfa.txt","w");
    while(1){
        c=getch();
        ///'14' ASCII KODU CTRL+N YENI SAYFA ACMA ISLEMI ACAR
        if (c==14){
            goto ctrln;
        }
        ///'15' ASCII KODU CTRL+O DOSYA ACMA ISLEMI YAPAR
        else if(c==15){
            ///ARAC CUBUGU BASLANGICI
            system("cls");
            printf("\t\t********** Metin Editoru (Notepad) **********\n\n");
            printf("Yeni: Ctrl+N\tAc: Ctrl+O\tKaydet: Ctrl+S");
            printf("\n-------------------------------------------------------------------------------\n");
            ///ARAC CUBUGU BITISI
            printf("Dosya adi giriniz: ");
            scanf("%s",dosyaadi);
            strcat(dosyaadi,".txt");
            dosya1=fopen(dosyaadi,"r");
            if(dosya1==NULL){
                printf("\n\tDosya Bulunamadi!");
                goto ctrlo;
            }
            while(!feof(dosya1)){
                c=getc(dosya1);
                printf("%c",c);
            }
            fclose(dosya1);
            dosya1=fopen(dosyaadi,"a");
            while(1){
                c=getch();
                if(c==19)
                    goto ctrlo;
                if(c==13){
                    c='\n';
                    printf("\n\t");
                    fputc(c,dosya1);
                }
                else{
                    printf("%c",c);
                    fputc(c,dosya1);
                }
            }
            ctrlo:
                fclose(dosya1);
                goto ctrln;
            getch();
        }
        ///'19' ASCII KODU CTRL+S KAYDETME ISLEMI YAPAR
        else if(c==19){
            fclose(dosya1);
            printf("\n\nDosya adi giriniz: ");
            scanf("%s",dosyaadi);
            strcat(dosyaadi,".txt");
            dosya1=fopen("GeciciSayfa.txt","r");
            dosya2=fopen(dosyaadi,"w");
            while(!feof(dosya1)){
                c=getc(dosya1);
                putc(c,dosya2);
            }
            fclose(dosya2);
            break;
        }
        ///'13' ASCII KODU ENTER BOSLUK BIRAKIR
        else if(c==13){
            c='\n';
            printf("\n");
            fputc(c,dosya1);
        }
        ///'08' ASCII KODU BACKSPACE KARAKTER SÝLER
        else if(c==8){
            printf("\b \b");
            /**dosyadaki yazýnýn silinmesi*/
        }
        else{
            printf("%c",c);
            fputc(c,dosya1);
        }
    }
}
///MAIN FONKSIYONU
int main(){
    ///KONSOL EKRANININ ARKAPLAN RENGINI BEYAZ (F) YAZI RENGINI SIYAH (0) YAPAR
    system("COLOR F0");
    while(1){
        Editor();
    }
}
