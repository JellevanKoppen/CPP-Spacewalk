class Location{
  public:
    void setBodyLocation(int index, int bodyID);
    //void setSpaceshipLocation(ind id, int location);
    void printLocations();
    void initiate(int _boardSize);
    virtual ~Location();
    Location();
    Location(int _boardSize);
  private:
    int boardSize;
    int *locationArray;
};
