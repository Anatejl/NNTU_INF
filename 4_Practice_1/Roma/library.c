//
// Created by Anatejl on 01.07.2024.
//

#include "library.h"


bool library_fill(Library_template* p_library){

    //Since we are cheburashkas, we hardcode the library.

    //1
    p_library[0].code = 0;
    p_library[0].UDK = 6182;
    strcpy(p_library[0].author, "Gabriel Marquez");
    strcpy(p_library[0].book_name, "Love in the Time of Cholera");
    p_library[0].year = 1985;
    p_library[0].inplace = true;

    //2
    p_library[1].code = 1;
    p_library[1].UDK = 943281;
    strcpy(p_library[1].author, "Chinua Achebe");
    strcpy(p_library[1].book_name, "Things Fall Apart");
    p_library[1].year = 1958;
    p_library[1].inplace = false;

    //3
    p_library[2].code = 2;
    p_library[2].UDK = 435715;
    strcpy(p_library[2].author, "Margaret Atwood");
    strcpy(p_library[2].book_name, "Oryx and Crake");
    p_library[2].year = 2003;
    p_library[2].inplace = true;

    //4
    p_library[3].code = 3;
    p_library[3].UDK = 541234;
    strcpy(p_library[3].author, "Kazuo Ishiguro");
    strcpy(p_library[3].book_name, "Never Let Me Go");
    p_library[3].year = 2005;
    p_library[3].inplace = false;

    //5
    p_library[4].code = 4;
    p_library[4].UDK = 656211;
    strcpy(p_library[4].author, "Isabel Allende");
    strcpy(p_library[4].book_name, "The House of the Spirits");
    p_library[4].year = 1982;
    p_library[4].inplace = true;

    //6
    p_library[5].code = 5;
    p_library[5].UDK = 10412;
    strcpy(p_library[5].author, "Haruki Murakami");
    strcpy(p_library[5].book_name, "Norwegian Wood");
    p_library[5].year = 1987;
    p_library[5].inplace = true;

    //7
    p_library[6].code = 6;
    p_library[6].UDK = 23671;
    strcpy(p_library[6].author, "Salman Rushdie");
    strcpy(p_library[6].book_name, "Midnight's Children");
    p_library[6].year = 1981;
    p_library[6].inplace = true;

    //8
    p_library[7].code = 7;
    p_library[7].UDK = 10412;
    strcpy(p_library[7].author, "Toni Morrison");
    strcpy(p_library[7].book_name, "Song of Solomon");
    p_library[7].year = 1977;
    p_library[7].inplace = true;

    //9
    p_library[8].code = 8;
    p_library[8].UDK = 67121;
    strcpy(p_library[8].author, "Jhumpa Lahiri");
    strcpy(p_library[8].book_name, "The Namesake");
    p_library[8].year = 2003;
    p_library[8].inplace = true;

    //10
    p_library[9].code = 9;
    p_library[9].UDK = 7021;
    strcpy(p_library[9].author, "Khaled Hosseini");
    strcpy(p_library[9].book_name, "The Kite Runner");
    p_library[9].year = 2003;
    p_library[9].inplace = true;

    //11
    p_library[10].code = 10;
    p_library[10].UDK = 23617;
    strcpy(p_library[10].author, "Zadie Smith");
    strcpy(p_library[10].book_name, "White Teeth");
    p_library[10].year = 2000;
    p_library[10].inplace = true;

    //12
    p_library[11].code = 11;
    p_library[11].UDK = 56231;
    strcpy(p_library[11].author, "Michael Ondaatje");
    strcpy(p_library[11].book_name, "The English Patient");
    p_library[11].year = 1992;
    p_library[11].inplace = false;

    //13
    p_library[12].code = 12;
    p_library[12].UDK = 81098;
    strcpy(p_library[12].author, "Ian McEwan");
    strcpy(p_library[12].book_name, "Atonement");
    p_library[12].year = 2001;
    p_library[12].inplace = true;

    //14
    p_library[13].code = 13;
    p_library[13].UDK = 14652;
    strcpy(p_library[13].author, "Alice Walker");
    strcpy(p_library[13].book_name, "The Color Purple");
    p_library[13].year = 1982;
    p_library[13].inplace = true;

    //15
    p_library[14].code = 14;
    p_library[14].UDK = 95712;
    strcpy(p_library[14].author, "Umberto Eco");
    strcpy(p_library[14].book_name, "The Name of the Rose");
    p_library[14].year = 1980;
    p_library[14].inplace = false;

    //16
    p_library[15].code = 15;
    p_library[15].UDK = 8420;
    strcpy(p_library[15].author, "Orhan Pamuk");
    strcpy(p_library[15].book_name, "My Name Is Red");
    p_library[15].year = 1998;
    p_library[15].inplace = true;

    //17
    p_library[16].code = 16;
    p_library[16].UDK = 1561;
    strcpy(p_library[16].author, "Donna Tartt");
    strcpy(p_library[16].book_name, "The Secret History");
    p_library[16].year = 1992;
    p_library[16].inplace = true;
    
    //18
    p_library[17].code = 17;
    p_library[17].UDK = 5612;
    strcpy(p_library[17].author, "Arundhati Roy");
    strcpy(p_library[17].book_name, "The God of Small Things");
    p_library[17].year = 1997;
    p_library[17].inplace = true;

    //19
    p_library[18].code = 18;
    p_library[18].UDK = 769212;
    strcpy(p_library[18].author, "David Mitchell");
    strcpy(p_library[18].book_name, "Cloud Atlas");
    p_library[18].year = 2004;
    p_library[18].inplace = false;

    //20
    p_library[19].code = 19;
    p_library[19].UDK = 41208;
    strcpy(p_library[19].author, "Elena Ferrante");
    strcpy(p_library[19].book_name, "My Brilliant Friend");
    p_library[19].year = 2011;
    p_library[19].inplace = true;

    //21
    p_library[20].code = 20;
    p_library[20].UDK = 6401;
    strcpy(p_library[20].author, "Colson Whitehead");
    strcpy(p_library[20].book_name, "The Underground Railroad");
    p_library[20].year = 2016;
    p_library[20].inplace = true;

    //22
    p_library[21].code = 21;
    p_library[21].UDK = 6401;
    strcpy(p_library[21].author, "Yann Martel");
    strcpy(p_library[21].book_name, "Life of Pi");
    p_library[21].year = 2001;
    p_library[21].inplace = true;

    //23
    p_library[22].code = 22;
    p_library[22].UDK = 6401;
    strcpy(p_library[22].author, "Jonathan Franzen");
    strcpy(p_library[22].book_name, "The Corrections");
    p_library[22].year = 2001;
    p_library[22].inplace = false;

    //24
    p_library[23].code = 23;
    p_library[23].UDK = 6401;
    strcpy(p_library[23].author, "Paulo Coelho");
    strcpy(p_library[23].book_name, "The Alchemist");
    p_library[23].year = 1988;
    p_library[23].inplace = true;

    //25
    p_library[24].code = 24;
    p_library[24].UDK = 6401;
    strcpy(p_library[24].author, "Hilary Mantel");
    strcpy(p_library[24].book_name, "Wolf Hall");
    p_library[24].year = 2009;
    p_library[24].inplace = true;
    
    return true;
}
