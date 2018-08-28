#include<iostream>
#include<string>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
int NUMBER=0; int ID=0;
int getID(){
return ++ID ;
}
int gethash(int id, float value, string name){
int hashvalue = (id*10)+ value + stoi(name);
return hashvalue;
}
int gethash(time_t timestamp,vector<string> data, int nodeNumber, string nodeId, string referenceNodeId, string childReferenceNodeId, string genesisReferenceNodeId){
int hashvalue = (((nodeNumber%100)* stoi(nodeId))+stoi(referenceNodeId)+stoi(childReferenceNodeId)+stoi(genesisReferenceNodeId))%100;
return hashvalue;
}
time_t getDate(){
     time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}
int getNumber(){
return ++NUMBER;
}

string encrypt(string str){
 for(i = 0; i < strlen(str); i++)
            str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value
return str;
}
struct Node{
    time_t timestamp;
    int nodeNumber;
    vector <string> data;
    string nodeId;
    string referenceNodeId;
    string childReferenceNodeId;
    string genesisReferenceNodeId;
    vector <string> HashValue;
};
Node* GenesisNode=NULL;
class dynamic_list{
    private: int id; float value; string name; vector <string> data; vector <string> HashValue; time_t timestamp;
             string referenceNodeId; string childReferenceNodeId; string genesisReferenceNodeId;
    public: create_genesis(){
                GenesisNode = new Node;
                GenesisNode->timestamp = getDate();
                cout<<"Owner Id :" ;cin>>id; data.push_back(id);
                cout<<"Value :" ; cin>>value; data.push_back(value);
                cout<<"Owner Name :"; getline(cin,name); data.push_back(name);
                int hashvalue = gethash(id,value, name); data.push_back(hashvalue);
                GenesisNode->data = data;
                GenesisNode->nodeNumber = getNumber();
                GenesisNode->nodeId = getID();
                GenesisNode->referenceNodeId = "NULL";
                GenesisNode->childReferenceNodeId = "NULL";
                GenesisNode->genesisReferenceNodeId = "0000";
                int hashvalue1;
                hashvalue1 = gethash(timestamp, data, nodeNumber, nodeId, referenceNodeId, childReferenceNodeId,genesisReferenceNodeId);
                HashValue.push_back(hashvalue1);
                GenesisNode->HashValue = HashValue;
                }
               void newnode(string referenceNodeId, string genesisReferenceNodeId){
                    Node newNode = new Node;
                    newNode->timestamp = getDate();
                    cout<<"Owner Id :" ;cin>>id; data.push_back(id);
                    cout<<"Value :" ; cin>>value; data.push_back(value);
                    cout<<"Owner Name :"; getline(cin,name); data.push_back(name);
                    int hashvalue = gethash(id,value, name); data.push_back(hashvalue);
                    newNode->data = encrypt(data);
                    newNode->nodeNumber = getNumber();
                    newNode->nodeNumber = getID();
                    newNode->referenceNodeId = referenceNodeId;
                    newNode->genesisReferenceNodeId = genesisReferenceNodeId;
                    int hashvalue1;
                    hashvalue1 = gethash(timestamp, data, nodeNumber, nodeId, referenceNodeId, childReferenceNodeId,genesisReferenceNodeId);
                    HashValue.push_back(hashvalue1);
                    newNode->HashValue = HashValue;
               }
               int getreferenceNodeId(){
                return referenceNodeId;
               }
               int getgenesisNodeId(){
                return genesisNodeId;
               }
               string getdata(int nodeId){
                Node* node = traverse(nodeId);
                return node->data;
               }
};
int main(){
    create_genesis();
    newnode(getreferenceNodeId(),getgenesisNodeId());
    encrypt(getdata(1)); decrypt(getdata(1));
return 0;
}
