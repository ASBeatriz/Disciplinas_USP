
void fila_apagar(FILA **f){
    if(*f == NULL) return;
    if((*f)->inicio == NULL){
        free(*f);
        *f = NULL;
        return;
    }

    item_apagar(&(*f)->inicio->item);
    fila_remover(*f);
    fila_apagar(f);
}
