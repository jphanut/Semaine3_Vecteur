#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

struct vector_t {
  int size;
  float *v;
};
// initialise le vecteur à la valeur du réel
struct vector_t * init(int, float);
// récupère le nième élément
float get(struct vector_t *, int) ;
// fixe la valeur du nième élément
void set(struct vector_t *, int , float);
// supprime un vecteur
void destroy(struct vector_t *);

#endif // VECTOR_H_INCLUDED
