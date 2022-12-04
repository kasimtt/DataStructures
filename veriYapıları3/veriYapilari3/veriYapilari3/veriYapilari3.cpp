
#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#define UZUNLUK 68
using namespace std;



int dizi1[] = { 1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,2001,2002,2003,2004,2013,2014,2015,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012,3013,3014,3015,3016,3017,3018,3019,3020,3021,3022,3023,3024,3025,3026,3027,3028,3029,3030,3031,3032,3033,3034,3035,3036,3037,3038,3039,3040,3041 };	//agac1 i�in kullan�lacak veriler
int dizi2[] = { 3041,3040,3039,3038,3037,3036,3035,3034,3033,3032,3031,3030,3029,3028,3027,3026,3025,3024,3023,3022,3021,3020,3019,3018,3017,3016,3015,3014,3013,3012,3011,3010,3009,3008,3007,3006,3005,3004,3003,3002,3001,2015,2014,2013,2004,2003,2002,2001,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064 };	//agac2 i�in kullan�lacak veriler
int dizi3[] = { 3039,1074,3010,1082,3016,3005,3008,3014,3015,3023,3025,2002,3021,3035,1077,1065,1069,1073,3011,2004,3020,3001,3030,1076,1081,3031,3040,1071,3013,3029,3036,3027,3033,1070,3038,1068,1080,3037,2014,3003,3007,1072,1066,1083,2015,2003,3018,3024,3034,3009,3012,3019,3028,1078,3017,2001,1079,3041,1067,2013,3026,1064,3004,3022,3006,1075,3032,3002 };	//agac3 i�in kullan�lacak veriler

struct Dugum {		//Agacta yer alan her bir dugumun veri yapisi
	int veri; 		//Dugumde tutulan veri
	Dugum* sag;	    //Dugumun sag cocuguna isaretci
	Dugum* sol;   //Dugumun sol cocuguna isaretci

};

struct IkiliSiralamaAgaci {	//Ikili siralama agaci veri yapisi
	Dugum* kok;			//Agac kokune isaretci
	void agacKur(int*);	//Dizi isaretcisi alir ve dizinin elemanlarini ikili siralama agacina uygun sekilde yerlestirir
	void agacKapat();		//Agacin dugumleri icin alinan bellek gozlerini program sonlanmadan hemen once iade eder
	void olustur();         // Agac olusturur
	int dugumSayisi;       //dugum sayisini tutar
    bool DFS(Dugum*, int);	//Ilk derinlik arama fonksiyonu bir agac koku ve aranacak deger parametrelerini alir
    bool BFS(Dugum*, int);  //Ilk genislik arama fonksiyonu bir agac koku ve aranacak deger parametrelerini alir
};








void IkiliSiralamaAgaci::olustur()
{
	kok = NULL;
	dugumSayisi = 0;
}

void Inorder(Dugum* nptr)   //Test icin inorder kulland�m. Testi gecti 
{
    if (nptr) {
        Inorder(nptr->sol);
        cout << nptr->veri << endl;
        Inorder(nptr->sag);
    }
}

void IkiliSiralamaAgaci::agacKur(int* eklenecek)
{
    Dugum* tara;
    Dugum* yeni = new Dugum();
   
    tara = kok;
   
    yeni->veri = *eklenecek;
    yeni->sag = NULL;
    yeni->sol = NULL;
   
    bool eklendi = false;
   
    if (kok == NULL) {
        kok = yeni;      //kok null ise koku olusturur
        return;
    }
    while ((tara != NULL) && (!eklendi))
    {
        if (yeni->veri < tara->veri)
        {
            if (tara->sol != NULL)
            {
                tara = tara->sol;
            }
            else
            {
                tara->sol = yeni;
                eklendi = true;
            }
        }
        else
            if (yeni->veri > tara->veri)
            {
                if (tara->sag != NULL)
                {
                    tara = tara->sag;
                }
                else
                {
                    tara->sag = yeni;
                    eklendi = true;
                }
            }
    }
}

int main()
{
    // asa��da a�aclar s�ras�yla tan�mlanm��t�r.
    IkiliSiralamaAgaci* birinciAgac = new IkiliSiralamaAgaci();
    IkiliSiralamaAgaci* ikinciAgac = new IkiliSiralamaAgaci();
    IkiliSiralamaAgaci* ucuncuAgac = new IkiliSiralamaAgaci();





    birinciAgac->olustur();//
    for (int i = 0; i < UZUNLUK; i++)
    {
        birinciAgac->agacKur(&dizi1[i]);
    }

    ikinciAgac->olustur();//
    for (int i = 0; i < UZUNLUK; i++)
    {
        ikinciAgac->agacKur(&dizi2[i]);
    }

    ucuncuAgac->olustur();//
    for (int i = 0; i < UZUNLUK; i++)
    {
        ucuncuAgac->agacKur(&dizi3[i]);
    }

    //Inorder(ikinciAgac->kok);  // test icin kullan�lan fonksiyon.
    bool bulduMu;
    int secim;
    int secim2;
    int veri;
    secim = 0;
    while (secim !=4)
    {   
        cout << endl<<"-------------------------------------------------------------"<<endl;
        cout << "Arama yapacaginiz agaci seciniz(1,2,3) cikis icin 4' e basin: ";
        cin >> secim;

        switch (secim)
        {
            
        case 1: cout << "1. agac icin arama yontemi giriniz(DFS:1, BFS:2) : ";
            cin >> secim2;
            if (secim2 == 1)
            {
                cout << "Aranacak veriyi giriniz : ";
                cin >> veri;
                bulduMu = birinciAgac->DFS(birinciAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";


            }
            else if (secim2 == 2)
            {
                cout << "aranacak veriyi giriniz: ";
                cin >> veri;
                bulduMu = birinciAgac->BFS(birinciAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";



            }
            else
                cout << "hatali giris yapt�n�z";
            break;
        case 2: cout << "2. agac icin arama yontemi giriniz(DFS:1, BFS:2) : ";
            cin >> secim2;
            if (secim2 == 1)
            {
                cout << "aranacak veriyi giriniz: ";
                cin >> veri;
                bulduMu = ikinciAgac->DFS(ikinciAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";
            }
            else if (secim2 == 2)
            {
                cout << "aranacak veriyi giriniz: ";
                cin >> veri;
                bulduMu = ikinciAgac->BFS(ikinciAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";
            }
            else
                cout << "hatali giris yaptiniz";
            break;
        case 3:cout << "3. agac icin arama yontemi giriniz(DFS:1, BFS:2) : ";
            cin >> secim2;
            if (secim2 == 1)
            {
                cout << "aranacak veriyi giriniz: ";
                cin >> veri;
                bulduMu = ucuncuAgac->DFS(ucuncuAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";
            }
            else if (secim2 == 2)
            {
                cout << "aranacak veriyi giriniz: ";
                cin >> veri;
                bulduMu = ucuncuAgac->BFS(ucuncuAgac->kok, veri);
                if (bulduMu)
                {
                    cout << "Veri Bulundu...";
                }
                else
                    cout << "Veri bulunamadi...";
            }
            else
                cout << "hatali giris yapt�n�z";
            break;
        case 4: cout << "cikis yaptiniz"; break;
        default:
            cout << "hatali giris yaptin tekrar dene";
            break;
        }
    }
}


bool IkiliSiralamaAgaci::DFS(Dugum* dugum, int aranacak_veri)
{
    auto begin = std::chrono::high_resolution_clock::now();
    IkiliSiralamaAgaci* p;
    stack<Dugum*> yigin;
    yigin.push(kok);
    int Sure;
    while (!yigin.empty())
    {
        dugum = yigin.top();
        yigin.pop();


        if (aranacak_veri == dugum->veri)
        {
           
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            Sure = elapsed.count();
            cout << "Gecen sure : " << Sure << endl;
            return 1;//veriyi bulmas� durumunda '1' yani true donecek
        }

        else
        {
            if (dugum->sag)
            {
                yigin.push(dugum->sag);
            }
            if (dugum->sol)
            {
                yigin.push(dugum->sol);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    Sure = elapsed.count();
    cout << "gecen sure : " << Sure << endl;
    return 0;//veriyi bulamamas� durumunda '0' yani false donecek
}

bool IkiliSiralamaAgaci::BFS(Dugum* dugum, int aranacak_veri)
{
    auto begin = std::chrono::high_resolution_clock::now();
    IkiliSiralamaAgaci* p;
    queue<Dugum*> kuyruk;
    kuyruk.push(kok);
    int Sure;
    while (!kuyruk.empty())
    {
        Dugum* dugum = kuyruk.front();
        kuyruk.pop();

        if (aranacak_veri == dugum->veri)
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            Sure = elapsed.count();
            cout << "gecen sure : " << Sure << endl;
            return 1;//veriyi bulmas� durumunda '1' yani true
        }

        else
        {
            if (dugum->sol)
            {
                kuyruk.push(dugum->sol);
            }
            if (dugum->sag)
            {
                kuyruk.push(dugum->sag);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    Sure = elapsed.count();
    cout << "gecen sure : " << Sure << endl;
    return 0;//veriyi bulamamas� durumunda '0' yani false doner.
}