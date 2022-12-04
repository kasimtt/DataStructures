
#include <iostream>
#include <chrono>

using namespace std;
int* dizi = new int[10000];

struct ArrayList {
    int* bas;                     //dizinin ba�lang�� adresini tutar
    void olustur();               //ba�lang�� i�in gereken tan�mlar� i�erir
    void ekle(int, int);          //de�er ve s�ra numaras� alarak ekleme yapar
    void guncelle(int, int);      //de�er ve s�ra numaras� alarak g�nceller
    void sil(int);                //s�ra numaras� alarak silme yapar
    void yazdir();                //liste i�eri�ini ekrana yazar
    void bosalt();                //listenin bellek alanlar�n� iade eder
    int sayac;                    //liste ka� eleman oldu�unu tutar
};



struct Node
{
    int deger;               //d���m�n say�sal de�eri
    Node* sonraki;          //sonraki d���me i�aret�i
};
struct LinkedList
{
    Node* bas;                  //listenin ba�lang�� adresini tutar
    void olustur();             //ba�lang�� i�in gereken tan�mlar� i�erir
    void ekle(int, int);        //de�er ve s�ra numaras� alarak ekleme yapar
    void guncelle(int, int);    //de�er ve s�ra numaras� alarak g�nceller
    void yazdir();              //liste i�eri�ini ekrana yazar
    void sil(int siraNo);       //sira no alarak silme
    void bosalt();              //listenin bellek alanlar�n� iade eder
    int sayac;                  //liste ka� eleman oldu�unu tutar
};

int main()
{
    // ekleme methodu icin linkedlist ve arraylist �al��mas� a�a��dad�r
    ArrayList* arraylist = new ArrayList();
    auto begin = std::chrono::high_resolution_clock::now();
    arraylist->olustur();
    for (int i=0; i < 1000; i++)
    {
        arraylist->ekle(i, i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "Array List'e " << arraylist->sayac  << " Veri Ekleme Suresi: " << elapsed.count() << " mikrosaniye" << endl;
    
    LinkedList* linkedlist = new LinkedList();
    auto begin2 = std::chrono::high_resolution_clock::now();
    linkedlist->olustur();
    
    for (int i = 0; i < 1000; i++)
    {
        linkedlist->ekle(i, i);
    }
    
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
    cout << "Linked List'e " << linkedlist->sayac << " Veri Ekleme Suresi: " << elapsed2.count() << " mikrosaniye" << endl;


    // g�ncelleme methodu icin linked list ve array list kar��last�rmas�...

    auto begin3 = std::chrono::high_resolution_clock::now();
    arraylist->olustur();
    for (int i = 0; i < 1000; i++)
    {
        arraylist->guncelle(i, i);
    }

    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
    cout << "Array List'e " << arraylist->sayac << " Veri guncelleme Suresi: " << elapsed3.count() << " mikrosaniye" << endl;

   
    auto begin4 = std::chrono::high_resolution_clock::now();
    linkedlist->olustur();

    for (int i = 0; i < 1000; i++)
    {
        linkedlist->ekle(i, i);
    }

    auto end4 = std::chrono::high_resolution_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - begin4);
    cout << "Linked List'e " << linkedlist->sayac << " Veri guncelleme Suresi: " << elapsed4.count() << " mikrosaniye" << endl;

    //sirasiz islem yaparsak nolur?? deneyelim
    
    cout << "***********rastgele islem yapilmasi sonucu elde edilen veriler************" << endl;
    
    
    auto begin5 = std::chrono::high_resolution_clock::now();
    arraylist->olustur();
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    { 
        int a = 1 + rand() % 900;  // rastgele siralara de�erler atama 
        arraylist->ekle(i,a);
    }
   
    auto end5 = std::chrono::high_resolution_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - begin5);
    cout << "Array List'e " << arraylist->sayac << " Rasgele Veri Ekleme Suresi: " << elapsed5.count() << " mikrosaniye" << endl;


    auto begin6 = std::chrono::high_resolution_clock::now();
    linkedlist->olustur();
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        int a = 1 + rand() % 900;  // rastgele siralara de�erler atama 
        linkedlist->ekle(a,i);
    }
  
    auto end6 = std::chrono::high_resolution_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::microseconds>(end6 - begin6);
    cout << "Linked List'e " << arraylist->sayac << " Rasgele Ekleme Suresi: " << elapsed6.count() << " mikrosaniye" << endl;



    return EXIT_SUCCESS;
}





void LinkedList::olustur()
{

    bas = NULL;
    sayac = 0;
}
void LinkedList::ekle(int n, int sira)
{

    Node* eklenenNode = new Node();
    eklenenNode->deger = n;
    Node* tara;
    tara = bas;
    

    if (bas == NULL)
    {
        bas = eklenenNode;
        sayac++;
    }

    else
    {
        for (int i = 1; i < sira - 1; i++)
        {
            tara = tara->sonraki;
        }
        eklenenNode->sonraki = tara->sonraki;
        tara->sonraki = eklenenNode;
        sayac++;
    }

    tara = bas;
}


void LinkedList::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara) {
        cout << "Liste bos!!!" << endl;
        return;
    }
    while (tara) {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}

void LinkedList::sil(int siraNo)
{
    Node* tara = new Node();
    Node* arka = new Node();

    tara = bas;
    sayac = 0;
    tara = bas;

    if (siraNo <= 0)
    {
        cout << " Negatif degerli sira mi olur dostum? " << endl;
        return;
    }
    if (siraNo == 1)
    {
        bas = bas->sonraki;
        delete tara;
        return;
    }
    while (tara != NULL && (sayac < siraNo))
    {
        arka = tara;
        tara = tara->sonraki;
        sayac++;
    }
    if (sayac < siraNo)
    {
        cout << "silinecek kayit bulunamadi \n";

    }
    else
    {
        arka->sonraki = tara->sonraki;
        delete tara;
    }


}


void LinkedList::guncelle(int sira, int yeni)
{
    Node* tara = new Node();
    Node* yeniNode = new Node();
    yeniNode->deger = yeni;
    int sayac1 = 1;
    tara = bas;
    while (tara && (sayac1 <= sira))
    {
        sayac1++;
        tara = tara->sonraki;
    }
    if (tara)
    {
        yeniNode->sonraki = tara->sonraki;
        *tara = *yeniNode;
    }
    else
        cout << "guncellenecek numara bulunamadi...\n";
}


void LinkedList::bosalt()
{
    Node* node = new Node();
    while (LinkedList::bas)
    {
        node = bas;
        bas = bas->sonraki;
        delete node;
    }
}


// buradan s�nrakiler array diziler icin yap�lan i�lemleri kapsamaktad�r.


void ArrayList::olustur()
{
    bas = dizi;
}


void ArrayList::ekle(int eklenen, int siraNo)
{
    if (sayac >= siraNo)
    {
        for (int i = sayac - 1; i >= siraNo; i--)
        {
            dizi[i + 1] = dizi[i];
        }
        dizi[siraNo] = eklenen;
        sayac++;
    }
    else
    {
        dizi[sayac - 1] = eklenen;
    }
}

void ArrayList::yazdir()
{
    if (bas == NULL)
    {
        cout << "Dizi Bos " << endl;
        return;
    }
    for (int i = 0; i < sayac; i++)
    {
        cout << dizi[i] << endl;
    }
}

void ArrayList::guncelle(int degisen, int siraNo)
{
    dizi[siraNo] = degisen;
}

void ArrayList::sil(int silinen)
{
    sayac--;
    for (int i = silinen; i < sayac; i++)
    {
        dizi[i] = dizi[i + 1];
    }
}

void ArrayList::bosalt()
{
    bas = NULL;
    sayac = 0;
    delete dizi;
}