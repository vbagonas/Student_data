# 1_uzduotis

--v0.2 aprašas--<br/>
<br/>
1000 studentų failo nuskaitymas užtruko: 0,0040161s;
1000 studentų failo rušiavimas į du vektorius užtruko: 0,0010028s;
1000 studentų vargšelių failo išvedimas užtruko: 0,0020065s;
1000 studentų kietiakų failo išvedimas užtruko: 0,0042582s;

10000 studentų failo nuskaitymas užtruko: 0,0464456s;
10000 studentų failo rušiavimas į du vektorius užtruko: 0,0030077s;
10000 studentų vargšelių failo išvedimas užtruko: 0,02052s;
10000 studentų kietiakų failo išvedimas užtruko: 0,0422889s;

100000 studentų failo nuskaitymas užtruko: 0,6203255s;
100000 studentų failo rušiavimas į du vektorius užtruko: 0,0390416s;
100000 studentų vargšelių failo išvedimas užtruko: 0,1956795s;
100000 studentų kietiakų failo išvedimas užtruko: 0,422144s;

1000000 studentų failo nuskaitymas užtruko: 2,867015s;
1000000 studentų failo rušiavimas į du vektorius užtruko: 0,375445s;
1000000 studentų vargšelių failo išvedimas užtruko: 1,96022s;
1000000 studentų kietiakų failo išvedimas užtruko: 4,326675s;

10000000 studentų failo nuskaitymas užtruko: 25,340175s;
10000000 studentų failo rušiavimas į du vektorius užtruko: 3,3882775s;
10000000 studentų vargšelių failo išvedimas užtruko: 19,698125s;
10000000 studentų kietiakų failo išvedimas užtruko: 43,370325s;

--v0.3 aprašas--<br/>
<br/>
Kompiuterio sistemos parametrai:<br/>
CPU: AMD Ryzen 7 2700X Eight-Core Processor 3.70 GHz<br/>
RAM: 16GB DDR4 3200Mhz<br/>
SSD: 1024GB PCIe 4.0 NVMe M.2 SSD Read/Write 7000/6000MB/s<br/>

1000 studentų failo nuskaitymas užtruko: 0,00901463s;
1000 studentų failo rušiavimas į du vektorius užtruko: 0,0015018s;
1000 studentų vargšelių failo išvedimas užtruko: 0,003018s;
1000 studentų kietiakų failo išvedimas užtruko: 0,0062541s;

10000 studentų failo nuskaitymas užtruko: 0,1113698s;
10000 studentų failo rušiavimas į du vektorius užtruko: 0,0185193s;
10000 studentų vargšelių failo išvedimas užtruko: 0,0287746s;
10000 studentų kietiakų failo išvedimas užtruko: 0,058086s;

100000 studentų failo nuskaitymas užtruko: 1,425625s;
100000 studentų failo rušiavimas į du vektorius užtruko: 0,2477555s;
100000 studentų vargšelių failo išvedimas užtruko: 0,2943993s;
100000 studentų kietiakų failo išvedimas užtruko: 0,6339548s;

1000000 studentų failo nuskaitymas užtruko: 6,437965s;
1000000 studentų failo rušiavimas į du vektorius užtruko: 1,1721225s;
1000000 studentų vargšelių failo išvedimas užtruko: 2,395445s;
1000000 studentų kietiakų failo išvedimas užtruko: 5,34436s;

10000000 studentų failo nuskaitymas užtruko: 52,916875s;
10000000 studentų failo rušiavimas į du vektorius užtruko: 9,489965;
10000000 studentų vargšelių failo išvedimas užtruko: 22,4707s;
10000000 studentų kietiakų failo išvedimas užtruko: 49,6949s;

![image](https://github.com/vbagonas/1_uzduotis/assets/76889117/9e38d194-d476-479c-acd3-29ea3820e5cb)<br/>

Išvados: Matoma, jog naudojant std::list<Studentai> programos sparta ženkliai sumažėja ir testavimai užtrunka ilgiau. Tad šiuo atveju norint spartesnės programos, tektų rinktis vector konteinerius.
