double checkWeight(){
    static loadCell {LOAD_CELL_PIN};
    double weight = 0;

    while(1){
        weight = digitalRead(loadCell);
        return weight;
    }
}