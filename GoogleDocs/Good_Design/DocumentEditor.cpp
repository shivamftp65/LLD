#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class DocumentElement{
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
        string text;
    public:
        TextElement(string text){
            this->text = text;
        }

        string render() override{
            return text;
        }
};

class ImageElement : public DocumentElement{
    private:
        string imagePath;
    public:
        ImageElement(string imagePath){
            this->imagePath = imagePath;
        }

        string render(){
            return "[Image: " + imagePath + "]";
        }
};

// NewLineElement represents a line break in the document.
class NewLineElement : public DocumentElement {
public:
    string render() override {
        return "\n";
    }
};

// TabSpaceElement represents a tab space in the document.
class TabSpaceElement : public DocumentElement {
public:
    string render() override {
        return "\t";
    }
};

class Document{
    private:
        vector<DocumentElement*> documentElements;
    public: 
        void addElement(DocumentElement* element){
            documentElements.push_back(element);
        }
        // Renders the document by concatenating the render output of all elements.
        string render() {
            string result;
            for (auto element : documentElements) {
                result += element->render();
            }
            return result;
        }
};

class Persistance{
    public:
        virtual void save(string data) = 0;
};

class FileStorage : public Persistance{
    public:
        void save(string data) override {
            ofstream outFile("document.txt");
            if (outFile) {
                outFile << data;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            } else {
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
};

class DatabaseStorage : public Persistance{
    public:
        void save(string data) override {
            cout<<"Saved to Database"<<endl;
        }
};

// DocumentEditor class managing client interactions
class DocumentEditor {
private:
    Document* document;
    Persistance* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistance* storage) {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath) {
        document->addElement(new ImageElement(imagePath));
    }

    // Adds a new line to the document.
    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    // Adds a tab space to the document.
    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument() {
        storage->save(renderDocument());
    }
};

int main(){
    Document* document = new Document();
    Persistance* persistence = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(document, persistence);

    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();
    
    return 0;
}