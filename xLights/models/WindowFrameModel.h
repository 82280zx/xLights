#ifndef WINDOWFRAMEMODEL_H
#define WINDOWFRAMEMODEL_H

#include "Model.h"


class WindowFrameModel : public ModelWithScreenLocation<BoxedScreenLocation>
{
    public:
        WindowFrameModel(wxXmlNode *node, const NetInfoClass &netInfo, bool zeroBased = false);
        virtual ~WindowFrameModel();

    protected:
        virtual void InitModel() override;

        virtual void AddTypeProperties(wxPropertyGridInterface *grid) override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;

    private:
        void InitFrame();
};

#endif // WINDOWFRAMEMODEL_H
