/**
 * by Jaroslaw Hirniak
 * 15 November 2014
 */

#define DEBUG

#include <string>
#include <functional>

// for debugging
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef function<int (string)> hfun;

/**
 * P - number of buckets, should be prime to avoid collisions
 * Returns hashing function onto P buckets.
 */
hfun hashFun(const int P) {
  return [P] (string s) {
    int hash = 0;
    for (auto c : s) {
      hash = ((hash + c) * 256) % P; 
    }
    return hash;
  };
}

#ifdef DEBUG
int main() {
  typedef pair<int, vector<string>> problem;
  vector<problem> problems {
    problem(7919, vector<string> {
      "Ala ma kota, kot ma ale, oboje maja faje, jak ja spala, to beda mieli faze!",
      "Budowa cebuli, szczegolnie wielozwojowa budowa ukladu nerwowego wskazuje na wysokie rozwiniecie funkcji poznawczych gatunkow i na niesamowicie rozwiniete procesy poznawcze...",
      "Budowa cebul, szczegolnie wielozwojowa budowa ukladu nerwowego wskazuje na wysokie rozwiniecie funkcji poznawczych gatunkow i na niesamowicie rozwiniete procesy poznawcze...",
      "Budowy cebuli, szczegolnie wielozwojowa budowa ukladu nerwowego wskazuje na wysokie rozwiniecie funkcji poznawczych gatunkow i na niesamowicie rozwiniete procesy poznawcze...",
      "Cebula",
      "Cebulb",
      "Cebulc",
      "Debula",
      "Bebula"
    }),
    problem(11, vector<string> {
      "Ala",
      "Kot",
      "arbuz",
      "kaputsta",
      "cebula"
    }),
    problem(1299827, vector<string> {
      "Ala",
      "Blb",
      "Alb",

      "Zyl raz pewien wielki konstruktor-wynalazca, ktory, nie ustajac, wymyslal urzadzenia niezwykle i"
      "najdziwniejsze stwarzal aparaty. Zbudowal byl sobie maszynke-okruszynke, ktora pieknie spiewala i nazwal ja"
      "ptaszydlo. Pieczetowal sie sercem smialym i kazdy atom, ktory wyszedl spod jego reki, nosil ow znak, ze dziwili "
      "sie potem uczeni, odnajdujac w widmach atomowych migotliwe serduszka. Zbudowal wiele pozytecznych" 
      "maszyn, wielkich i malych, az naszedl go pomysl dziwaczny, aby smierc z zyciem w jedno zlaczyc i tak dopiac"
      "niemozliwosci. Postanowil zbudowac istoty rozumne z wody, ale nie tym okropnym sposobem, o ktorym zaraz "
      "pomyslicie. Nie, mysl o cialach miekkich i mokrych byla mu obca, brzydzil sie jej jak kazdy z nas. Zamierzyl"
      "zbudowac z wody istoty prawdziwie piekne i madre, wiec krystaliczne. Wybral tedy planete, bardzo od "
      "wszystkich slonc oddalona, z zamarzlego jej oceanu wysieki gory lodowe i z nich, jak z krysztalu gorskiego, "
      "wyciosal Kryonidow. Zwali sie tak, bo tylko w przerazliwym mrozie istniec mogli i w pustce bezslonecznej. "
      "Pobudowali tez w niedlugim czasie miasta i palace lodowe, a ze wszelkie cieplo grozilo im zguba, zorze polarne "
      "lapali do wielkich naczyn przejrzystych i nimi oswietlali swoje siedziby. Im kto byl wsrod nich mozniejszy, tym "
      "wiecej mial zorz polarnych, cytrynowych i srebrzystych, i zyli sobie szczesliwie, a ze sie nie tylko w swietle, ale "
      "i w szlachetnych kamieniach kochali, slyneli ze swych klejnotow. Klejnoty te byly z zamarznietych gazow ciete "
      "i szlifowane. Barwily im wieczna ich noc, w ktorej, jak duchy uwiezione, plonely wysmukle zorze polarne, "
      "podobne do zakletych mglawic w klodach z krysztalu. Niejeden zdobywca kosmiczny chcial posiasc te "
      "bogactwa, cala bowiem Kryonia byla z najwiekszych dali widoczna, migocac bokami jak klejnot, obracany z "
      "wolna na czarnym aksamicie. Przybywali wiec awanturnicy na Kryonie, by szczescia wojennego probowac. "
      "Przylecial na nia elektrycerz Mosiezny, ktory stapal, jakby dzwon dzwonil, ale zaledwie na lodach noge"
      "postawil, stopily sie od goraca i runal w otchlan lodowego oceanu, a wody zamknely sie nad nim i, jak owad w "
      "bursztynie, w gorze lodowej na dnie morz kryonskich po dzien ostatni spoczywa.",
      
      "Nie odstraszyl los Mosieznego innych smialkow. Przylecial po nim elektrycerz Zelazny, opiwszy sie plynnym "
      "helem, az mu w stalowym wnetrzu bulgotalo, a szron, osiadajacy na pancerzu, uczynil go do kukly sniegowej" 
      "podobnym. Ale szybujac ku powierzchni planety rozpalil sie od tarcia atmosferycznego, hel plynny wyparowal z "
      "niego swiszczac, a on sam, swiecac czerwono, na skaly lodowe upadl, ktore zaraz sie otwarly. Wydobyl sie, para "
      "buchajac, podobny do gejzera wrzacego, lecz wszystko, czego sie tknal, stawalo bialym oblokiem, z ktorego  "
      "snieg padal. Usiadl wiec i czekal, az ostygnie, a gdy juz gwiazdki sniegowe przestaly topniec mu na pancernych "
      "naramiennikach, chcial wstac i ruszyc w boj, lecz smar stezal mu w stawach i nie mogl nawet grzbietu "
      "wyprostowac. Do dzisiaj tak siedzi, a snieg padajacy uczynil go biala gora, z ktorej tylko ostrze helmu wystaje. "
      "Nazywaja te gore Zelazna, a w oczodolach jej lsni wzrok zamarzniety",

      "Poslyszal o losie poprzednikow trzeci elektrycerz, Kwarcowy, ktorego w dzien nie widac bylo inaczej jak "
      "soczewke polerowana, a w nocy jak odbicie gwiazd. Nie obawial sie, ze mu olej w czlonkach stezeje, bo go nie "
      "mial, ani ze lodowe kry pod nogami mu pekna, mogl bowiem zimnym stawac sie, jak chcial. Jednego musial"
      "unikac, to jest myslenia uporczywego, od niego bowiem rozgrzewal mu sie kwarcowy mozg i to moglo go "
      "zgubic. Ale postanowil sobie bezmyslnoscia zywot uratowac i zwyciestwo nad Kryonidami osiagnac. Przylecial"
      "na planete, a taki byl dluga podroza przez wieczna noc galaktyczna zmrozony, ze meteory zelazne, ktore sie o "
      "jego piers w locie ocieraly, trzaskaly na kawalki dzwoniac jak szklo. Osiadl na bialych sniegach Kryonii, pod jej "
      "niebem czarnym jak garnek pelny gwiazd i, podobny do lustra przejrzystego, chcial sie zastanowic, co ma "
      "poczac dalej, ale juz snieg wokol niego sczernial i poczal parowac. ",


      "Roslyszal o losie poprzednikow trzeci elektrycerz, Kwarcowy, ktorego w dzien nie widac bylo inaczej jak "
      "soczewke polerowana, a w nocy jak odbicie gwiazd. Nie obawial sie, ze mu olej w czlonkach stezeje, bo go nie "
      "mial, ani ze lodowe kry pod nogami mu pekna, mogl bowiem zimnym stawac sie, jak chcial. Jednego musial"
      "unikac, to jest myslenia uporczywego, od niego bowiem rozgrzewal mu sie kwarcowy mozg i to moglo go "
      "zgubic. Ale postanowil sobie bezmyslnoscia zywot uratowac i zwyciestwo nad Kryonidami osiagnac. Przylecial"
      "na planete, a taki byl dluga podroza przez wieczna noc galaktyczna zmrozony, ze meteory zelazne, ktore sie o "
      "jego piers w locie ocieraly, trzaskaly na kawalki dzwoniac jak szklo. Osiadl na bialych sniegach Kryonii, pod jej "
      "niebem czarnym jak garnek pelny gwiazd i, podobny do lustra przejrzystego, chcial sie zastanowic, co ma "
      "poczac dalej, ale juz snieg wokol niego sczernial i poczal parowac. ",

      "Poslyszal o losie poprzednikow trzeci elektrycerz, Kwarcowy, ktorego w dzien nie widac bylo inaczej jak "
      "soczewke polerowana, a w nocy jak odbicie gwiazd. Nie obawial sie, ze mu olej w czlonkach stezeje, bo go nie "
      "mial, ani ze lodowe kry pod nogami mu pekna, mogl bowiem zimnym stawac sie, jak chcial. Jednego musial"
      "unikac, to jest myslenia uporczywego, od niego bowiem rozgrzewal mu sie kwarcowy mozg i to moglo go "
      "zgubic. Ale postanowil sobie bezmyslnoscia zywot uratowac i zwyciestwo nad Kryonidami osiagnac. Przylecial"
      "na planete, a taki byl dluga podroza przez wieczna noc galaktyczna zmrozony, ze meteory zelazne, ktore sie o "
      "jego piers w locie ocieraly, trzaskaly na kawalki dzwoniac jak szklo. Osiadl na bialych sniegach Kryonii, pod jej "
      "niebem czarnym jak garnek pelny gwiazd i, podobny do lustra przejrzystego, chcial sie zastanowic, co ma "
      "poczac dalej, ale juz snieg wokol niego sczernial i poczal parowac.",

      "Poslyszal o losie poprzednikow trzeci elektrycerz, Kwarcowy, ktorego w dzien nie widac bylo inaczej jak "
      "soczewke polerowana, a w nocy jak odbicie gwiazd. Nie obawial sie, ze mu olej w czlonkach stezeje, bo go nie "
      "mial, ani ze lodowe kry pod nogami mu pekna, mogl bowiem zimnym stawac sie, jak chcial. Jednego musial"
      "unikac, to jest myslenia uporczywego, od niego bowiem rozgrzewal mu sie kwarcowy mozg i to moglo go "
      "zgubic. Ale postanowil sobie bezmyslnoscia zywot uratowac i zwyciestwo nad Kryonidami osiagnac. Przylecial"
      "na planete, a taki byl dluga podroza przez wieczna noc galaktyczna zmrozony, ze meteory zelazne, ktore sie o "
      "jego piers w locie ocieraly, trzaskaly na kawalki dzwoniac jak szklo. Osiadl na bialych sniegach Kryonii, pod jej "
      "niebem czarnym jak garnek pelny gwiazd i, podobny do lustra przejrzystego, chcial sie zastanowic, co ma "
      "poczac dalej, ale juz snieg wokol niego sczernial i poczal parowac,",
    })
  };

  for (auto p : problems) {
    cout << endl << "Hashing onto " << p.first << " buckets:" << endl;
    hfun hash = hashFun(p.first);
    for (auto s : p.second) {
      cout << "Hash for \"" << s << "\" = " << hash(s) << endl;
    }
  }
  cout << endl;

  return 0;
}

#else

int main() {
  return 0;
}

#endif
