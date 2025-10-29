#include <iostream>

#include <RWGltf_CafReader.hxx>
#include <RWGltf_CafWriter.hxx>
// Meshing
#include <Standard_Version.hxx>
#include <BRep_Builder.hxx>
#include <Message_ProgressRange.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <TopoDS_Shape.hxx>
#include <RWMesh_CoordinateSystem.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_LabelSequence.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_VisMaterial.hxx>
#include <XCAFDoc_VisMaterialTool.hxx>

// https://github.com/FreeCAD/FreeCAD/blob/main/src/Mod/Import/App/ReaderGltf.cpp
// class ReaderGltf
// {
// public:
//     explicit ReaderGltf(const Base::FileInfo& file);

//     void read(Handle(TDocStd_Document) hDoc);
//     bool cleanup() const;
//     void setCleanup(bool);

// private:
//     TopoDS_Shape fixShape(TopoDS_Shape);
//     void processDocument(Handle(TDocStd_Document) hDoc);
//     TopoDS_Shape processSubShapes(Handle(TDocStd_Document) hDoc,
//                                   const TDF_LabelSequence& subShapeLabels);

// private:
//     Base::FileInfo file;
//     bool clean = true;
// };


int main() {
    std::cout << "Hello World!";
    
    // `Handle` is smart pointer
    Handle(TDocStd_Document) hDoc;
    const double unit = 0.001;  // mm
    RWGltf_CafReader aReader;
    aReader.SetSystemLengthUnit(unit);
    aReader.SetSystemCoordinateSystem(RWMesh_CoordinateSystem_Zup);
    aReader.SetDocument(hDoc);
    aReader.SetParallel(true);

    TCollection_AsciiString filename("..\\..\\cube.glb");
    Standard_Boolean ret = aReader.Perform(filename, Message_ProgressRange());
    std::cout << "ret: " << ret;
    return 0;
}
