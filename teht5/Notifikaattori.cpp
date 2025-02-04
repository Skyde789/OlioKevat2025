#include "Notifikaattori.h"

Notifikaattori::Notifikaattori()
{
}

void Notifikaattori::lisaa(Seuraaja* ptr)
{ 
	// asetetaan meidän vanha ensimmäinen listasta uuden pointerin seuraavaksi
	ptr->next = seuraajat;


	// asetetaan listan ensimmäiseksi uusi pointteri
	seuraajat = ptr;

}

void Notifikaattori::poista(Seuraaja* ptr)
{
	Seuraaja* i = seuraajat;

	while (i != nullptr) {
		if (i->next == ptr)
		{
			i->next = i->next->next;
		}

		i = i->next;
	}


	cout << "Pointer " << ptr->getNimi() << " poistettu listasta!\n";
}

void Notifikaattori::tulosta()
{
	Seuraaja* i = seuraajat;

	while (i != nullptr) {
		cout << i->getNimi() << endl;

		i = i->next;
	}
}

void Notifikaattori::postita(string n)
{
	Seuraaja* i = seuraajat;

	while (i != nullptr) {
		i->paivitys(n);

		i = i->next;
	}
}

void Notifikaattori::ReverseList()
{
	Seuraaja* cur = seuraajat;
	Seuraaja* next = cur->next;
	Seuraaja* previous = nullptr;

	while (cur != nullptr) {
		next = cur->next;
		cur->next = previous;
		previous = cur;
		cur = next;
	}

	cout << "Linked list kaannetty!" << endl;

	seuraajat = previous;
}
