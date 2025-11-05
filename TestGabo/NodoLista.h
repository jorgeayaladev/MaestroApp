template <class T>
class NodoLista
{
private:
	//propiedades o atributos
	T elem;
	NodoLista* sgte;
public:
	//Constructores
	NodoLista()
	{
		sgte = nullptr;
	}
	NodoLista(T pelem)
	{
		elem = pelem;
		sgte = nullptr;
	}
	
	//Métodos Setter / Getter
	void set_Elem(T pelem)
	{
		elem = pelem;
	}
	T get_Elem()
	{
		return elem;
	}
	void set_Sgte(NodoLista* pSgte)
	{
		sgte = pSgte;
	}
	NodoLista* get_Sgte()
	{
		return sgte;
	}

	//Métodos de Servicio
	bool es_vacio()
	{
		return sgte == NULL;
	}

};
