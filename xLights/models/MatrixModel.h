#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H

#include "Model.h"


class MatrixModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
        MatrixModel(wxXmlNode *node, const ModelManager &manager, bool zeroBased = false);
        virtual ~MatrixModel();
        virtual int GetNumStrands() const override;

        virtual bool StrandsZigZagOnString() const override { return true;};

        virtual bool SupportsXlightsModel() override { return true; }
        virtual void ExportXlightsModel() override;
        virtual void ImportXlightsModel(std::string filename, xLightsFrame* xlights, float& min_x, float& max_x, float& min_y, float& max_y) override;

        virtual void AddTypeProperties(wxPropertyGridInterface *grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;

    protected:
        virtual void AddStyleProperties(wxPropertyGridInterface *grid);
    
        MatrixModel(const ModelManager &manager);
        virtual void InitModel() override;
    
        void InitVMatrix(int firstExportStrand = 0);
        void InitHMatrix();
    
        bool vMatrix;
    private:
};

#endif // MATRIXMODEL_H
