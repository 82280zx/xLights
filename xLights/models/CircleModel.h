#ifndef CIRCLEMODEL_H
#define CIRCLEMODEL_H

#include "Model.h"


class CircleModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
        CircleModel(wxXmlNode *node, const ModelManager &manager, bool zeroBased = false);
        virtual ~CircleModel();

        virtual int GetStrandLength(int strand) const override;
        virtual int MapToNodeIndex(int strand, int node) const override;
        virtual int GetNumStrands() const override;
        virtual bool AllNodesAllocated() const override;

        virtual void AddTypeProperties(wxPropertyGridInterface *grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;

    protected:
        virtual void InitModel() override;
        
    private:
        void SetCircleCoord();
        void InitCircle();

        std::vector<int> circleSizes;
};

#endif // CIRCLEMODEL_H
