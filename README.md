# 1_uzduotis

--v0.2 aprašas--<br/>
<br/>
1000 studentų failo nuskaitymas užtruko: 0,0040161s;<br/>
1000 studentų failo rušiavimas į du vektorius užtruko: 0,0010028s;<br/>
1000 studentų vargšelių failo išvedimas užtruko: 0,0020065s;<br/>
1000 studentų kietiakų failo išvedimas užtruko: 0,0042582s;<br/>

10000 studentų failo nuskaitymas užtruko: 0,0464456s;<br/>
10000 studentų failo rušiavimas į du vektorius užtruko: 0,0030077s;<br/>
10000 studentų vargšelių failo išvedimas užtruko: 0,02052s;<br/>
10000 studentų kietiakų failo išvedimas užtruko: 0,0422889s;<br/>

100000 studentų failo nuskaitymas užtruko: 0,6203255s;<br/>
100000 studentų failo rušiavimas į du vektorius užtruko: 0,0390416s;<br/>
100000 studentų vargšelių failo išvedimas užtruko: 0,1956795s;<br/>
100000 studentų kietiakų failo išvedimas užtruko: 0,422144s;<br/>

1000000 studentų failo nuskaitymas užtruko: 2,867015s;<br/>
1000000 studentų failo rušiavimas į du vektorius užtruko: 0,375445s;<br/>
1000000 studentų vargšelių failo išvedimas užtruko: 1,96022s;<br/>
1000000 studentų kietiakų failo išvedimas užtruko: 4,326675s;<br/>

10000000 studentų failo nuskaitymas užtruko: 25,340175s;<br/>
10000000 studentų failo rušiavimas į du vektorius užtruko: 3,3882775s;<br/>
10000000 studentų vargšelių failo išvedimas užtruko: 19,698125s;<br/>
10000000 studentų kietiakų failo išvedimas užtruko: 43,370325s;<br/>

--v0.3 aprašas--<br/>
<br/>
Kompiuterio sistemos parametrai:<br/>
CPU: AMD Ryzen 7 2700X Eight-Core Processor 3.70 GHz<br/>
RAM: 16GB DDR4 3200Mhz<br/>
SSD: 1024GB PCIe 4.0 NVMe M.2 SSD Read/Write 7000/6000MB/s<br/>

1000 studentų failo nuskaitymas užtruko: 0,00901463s;<br/>
1000 studentų failo rušiavimas į du vektorius užtruko: 0,0015018s;<br/>
1000 studentų vargšelių failo išvedimas užtruko: 0,003018s;<br/>
1000 studentų kietiakų failo išvedimas užtruko: 0,0062541s;<br/>

10000 studentų failo nuskaitymas užtruko: 0,1113698s;<br/>
10000 studentų failo rušiavimas į du vektorius užtruko: 0,0185193s;<br/>
10000 studentų vargšelių failo išvedimas užtruko: 0,0287746s;<br/>
10000 studentų kietiakų failo išvedimas užtruko: 0,058086s;<br/>

100000 studentų failo nuskaitymas užtruko: 1,425625s;<br/>
100000 studentų failo rušiavimas į du vektorius užtruko: 0,2477555s;<br/>
100000 studentų vargšelių failo išvedimas užtruko: 0,2943993s;<br/>
100000 studentų kietiakų failo išvedimas užtruko: 0,6339548s;<br/>

1000000 studentų failo nuskaitymas užtruko: 6,437965s;<br/>
1000000 studentų failo rušiavimas į du vektorius užtruko: 1,1721225s;<br/>
1000000 studentų vargšelių failo išvedimas užtruko: 2,395445s;<br/>
1000000 studentų kietiakų failo išvedimas užtruko: 5,34436s;<br/>

10000000 studentų failo nuskaitymas užtruko: 52,916875s;<br/>
10000000 studentų failo rušiavimas į du vektorius užtruko: 9,489965;<br/>
10000000 studentų vargšelių failo išvedimas užtruko: 22,4707s;<br/>
10000000 studentų kietiakų failo išvedimas užtruko: 49,6949s;<br/>

![image](https://github.com/vbagonas/1_uzduotis/assets/76889117/9e38d194-d476-479c-acd3-29ea3820e5cb)<br/>

Išvados: Matoma, jog naudojant std::list<Studentai> programos sparta ženkliai sumažėja ir testavimai užtrunka ilgiau. Tad šiuo atveju norint spartesnės programos, tektų rinktis vector konteinerius.
