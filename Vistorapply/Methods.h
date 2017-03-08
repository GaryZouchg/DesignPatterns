
#pragma once


class IMethods
{
public:
    virtual void DataPrint( int i ) = 0;
    virtual void DataPrint( double d ) = 0;
    virtual void DataPrint( bool f ) = 0;
    virtual void DataPrint( std::string str ) = 0;
};


class Methods : public IMethods
{
public:
    virtual void DataPrint( int i )
    {
        std::cout<<"int "<<std::endl;
    }
    virtual void DataPrint( double d ) 
    {
        std::cout<<"double"<<std::endl;
    }
    virtual void DataPrint( bool f ) 
    {
        std::cout<<"bool"<<std::endl;
    }
    virtual void DataPrint( std::string str ) 
    {
        std::cout<<"string"<<std::endl;
    }

};