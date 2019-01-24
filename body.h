class Body{
  public:
    void sayHi();
    void setID(int _id);
    int getID();
    virtual ~Body();
    void print();
  private:
    int id;
};
