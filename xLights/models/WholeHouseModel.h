#ifndef WHOLEHOUSEMODEL_H
#define WHOLEHOUSEMODEL_H

#include "Model.h"


//somewhat deprecated as the ModelGroup is more likely to be used.  However, older rgbeffects.xml may have these in them
class WholeHouseModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
        WholeHouseModel(wxXmlNode *node, const ModelManager &manager, bool zb = false);
        virtual ~WholeHouseModel();

    protected:
        WholeHouseModel(const ModelManager &manager);
        virtual void InitModel() override;
        void InitWholeHouse(const std::string &WholeHouseData);
    private:
};

#endif // WHOLEHOUSEMODEL_H
