#ifndef SRC_MODEL_SCENE
#define SRC_MODEL_SCENE

#include "model/IScene.h"

namespace model {
class Scene : public IScene {
private:
    std::set<std::unique_ptr<IRenderable>> objects_;

public:
    Scene() = default;
    ~Scene() override = default;

    [[nodiscard]] std::set<std::unique_ptr<IRenderable>> const& getObjects()
        const override {
        return objects_;
    }
    void AddObject(std::unique_ptr<IRenderable> object) override {}
    void RemoveObject(IRenderable const& object) override {}
};

}  // namespace model

#endif /* SRC_MODEL_SCENE */
