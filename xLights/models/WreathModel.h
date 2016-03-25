#ifndef WREATHMODEL_H
#define WREATHMODEL_H

#include "Model.h"


class WreathModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
        WreathModel(wxXmlNode *node, const NetInfoClass &netInfo, bool zeroBased = false);
        virtual ~WreathModel();

        virtual void AddTypeProperties(wxPropertyGridInterface *grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;
    
    protected:
        virtual void InitModel() override;

    private:
        void InitWreath();
};

#endif // WREATHMODEL_H
