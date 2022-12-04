// KuyrukYiginOdevi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


struct Dugum {
    int veri;             //düðümün sayýsal deðeri
    Dugum* sonraki;       //sonraki düðüme iþaretçi
};
struct Kuyruk {
    Dugum* bas;          //kuyruðun baþýndaki elemanýn adresini tutar
    Dugum* son;          //kuyruðun sonundaki elemanýn adresini tutar
    void olustur();      //baþlangýç için gereken tanýmlarý içerir
    void kapat();        //program bitiminde bellek iadesi yapar
    void ekle(int);       //kuyruða yeni veri ekler
    int cikar();         //kuyruktan sýradaki elemaný çýkarýr
    bool bosMu();        //kuyruk boþ mu kontrol eder
};


struct Yigin {
    Kuyruk k1, k2;       //yýðýn için kullanýlacak kuyruk deðiþkenleri
    void olustur();     //baþlangýç için gereken tanýmlarý içerir
    void kapat();       //program bitiminde bellek iadesi yapar
    void ekle(int);     //kuyruða yeni veri ekler
    int cikar();         //kuyruktan sýradaki elemaný çýkarýr
    bool bosMu();       //kuyruk boþ mu kontrol eder
    int tepe();          //yýðýnýn tepesindeki elemaný okur
    void yazdir();       //yýðýn elemanlarýný sýrayla ekrana yazar
    int boyut;          //yýðýnda bulunan veri sayýsý tutar
    
};

void siraliEkle(Yigin*, int);
void yiginCikar(Yigin*);
int main()
{
    Yigin* yigin = new Yigin();
    yigin->olustur();
   /*
    yigin->ekle(1);
    yigin->ekle(2);                   // EKLEME SIRASINA GÖRE SÝRALAMA MEVCUT
    yigin->ekle(3);
    yigin->yazdir();
    cout << endl;
    cout << "cikarma methodu kullanildiktan sonra " << endl;
    yigin->cikar();  //  ilk giren ilk cikarilir
    yigin->yazdir();
    
    cout << endl;
    cout << "siralama sonrasinda  ";
    */
    siraliEkle(yigin,8);
    siraliEkle(yigin, 4);
    siraliEkle(yigin, 7);
    siraliEkle(yigin, 3);
    siraliEkle(yigin, 1);
    
    yiginCikar(yigin);
    yigin->yazdir();

   
    getchar();

    return EXIT_SUCCESS;
}

          // kuyruk yapýsý için methodlar aþaðýdakiler gibidir
          //referans olarak hocamýzýn dersteki örneði alýnmýþtýr.

void Kuyruk::olustur()
{
    bas = NULL;
    son = NULL;
}
void Kuyruk::kapat()
{
    Dugum* p;
    while (bas)
    {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}

void Kuyruk::ekle(int yeni)
{
    Dugum* yenidugum = new Dugum;
    yenidugum->veri = yeni;
    yenidugum->sonraki = NULL;
    if (bas == NULL)
    {
        bas = yenidugum;
        son = bas;
    }
    else
    {
        son->sonraki = yenidugum;
        son = yenidugum;
    }

}

int Kuyruk::cikar()
{
    Dugum* ustDugum;
    int gecici;
    ustDugum = bas;
    bas = bas->sonraki;
    gecici = ustDugum->veri;
    delete ustDugum;
    return gecici;
}

bool Kuyruk::bosMu()
{
    return bas == NULL;
}


// yýðýn için methodlar aþaðýdaki gibidir

void Yigin::olustur()
{
    boyut = 0;
}

void Yigin::kapat()
{
    
}

void Yigin::ekle(int eklenen)
{
    boyut++;
    k1.ekle(eklenen);
    while (!k1.bosMu())
    {
        k2.ekle(k1.bas->veri);
        k1.cikar();
    }
    Kuyruk temp = k1;
    k1 = k2;
    k2 = temp;
}

int Yigin::cikar()
{
    if (k1.bosMu())
        return 0;
    k1.cikar();
    boyut--;
    return boyut;
}

int Yigin:: tepe()
{
    if (k1.bosMu())
        return -1;
    return k1.bas->veri;
}

bool Yigin::bosMu()
{
    if (k1.bosMu())
        return true;
    return false;
}

void Yigin::yazdir()
{
    Dugum* temp = new Dugum();
    temp = k1.bas;
    cout << "stack son durumu : " << endl;
    while (temp->sonraki)
    {
        cout << temp->veri << " ";
        temp = temp->sonraki;
    }
    cout << temp->veri;
}

void yiginCikar(Yigin* s) 
{
    if (s->bosMu())
    {
        int x = s->cikar();
        yiginCikar(s);
        siraliEkle(s, x);
    }

}

void siraliEkle(Yigin* s, int x)
{
    if (s->bosMu() or x > s->tepe())
    {
        s->ekle(x);
        return;
    }

    int temp = s->cikar();
    siraliEkle(s, x);
    s->ekle(temp);
}

