// stack-que.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

struct BLISTE
{
    int bilgi;
        BLISTE *arka;
        
}*ilk,*son;


int ekle(BLISTE *ki)
{
    if (ilk != NULL) {
        son->arka = ki;
        son = ki;
        son->arka = NULL;
    }
    else {
        ilk = ki;
        son = ilk;
        ilk->arka = NULL;
    }
    return 0;
}

BLISTE* ara(int aranan)
{
    BLISTE* p;
    p = ilk;
    while (p) {
        if (p->bilgi == aranan)
            return p;
        p = p->arka;
    }
    return NULL;
}

BLISTE* sil(int silinecek)
{
    BLISTE* p, * bironceki;
    p = ilk;
    bironceki = NULL;
    while (p) {
        if (silinecek == p->bilgi)
            break;
        bironceki = p;
        p = p->arka;
    }
    if (p == ilk) {
        ilk = ilk->arka;
    }
    else if (p == son)
    {
        bironceki ->arka = NULL;
        son = bironceki;
    }
    else if (p==p){
        bironceki->arka = p->arka;
    }
    free(p);
    return p;

}

int listele()
{
    BLISTE* p;
    p = ilk;
    if (p==NULL)
    {
        return-1;

    }
    while (p)
    {
        cout << p->bilgi;
        p = p->arka;
    }
    return 1907;
}

int main()
{
    int ch;
    int secim, data;
    struct node* head = NULL;
    cout << "1-Ekle\n";
    cout << "2-Listele\n";
    cout << "3-Arama\n";
    cout << "4-Sil\n";

    do
    {
        cout << "Secimin???: \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            printf("Eklemek istediginiz degerini giriniz..?");
            scanf("%d", &data);
            head = addhead(head, data);
            break;
        case 2:
            printf("Eklemek istediginiz degerini giriniz..?");
            scanf("%d", &data);
            head = addlast(head, data);
            break;
        case 3:
            print(head);
            break;
        case 4:
            printf("Silmek istediginiz degerini giriniz..?");
            scanf("%d", &data);
            head = delete(head, data);
            break;
        case 5:
            head = destroy(head);
            break;
        case 6:
            printf("Listede %d eleman vardir\n", count(head));
            break;
        case 7:
            listinfo(head);
            break;
        case 8:
            exit(1);
            break;
        default: printf("Yanlis secim\n");
        }

    } while (ch=!4);
    return 1907;


   
  

}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
