#include "DXUT.h"
#include "SceneManager.h"
#include "10DUCKEngine.h"
#include <time.h>

SceneManager::Scene SceneManager::current_scene;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(Scene scene, bool camera_clear)
{
	srand(time(NULL));
	current_scene = scene;
	if (camera_clear)
	{
		Camera::position = { 0,0 };
		Camera::rotation = 0;
		Camera::scale = 1;
	}

	ObjectManager::Clear();

	switch (scene)
	{
	case SceneManager::Scene::Main:
		SoundManager::PlayBGM(L"Source/test.wav");

		ObjectManager::Instantiate<UIImage>({ 1200,660 })->z = 10;	// ��ο� �켱���� ����

		ObjectManager::Instantiate<Text>({ 0,300 })->SetText(L"����Ű �̵� WASD ī�޶� ����\n���̵� �����̽���", { 0.5,0.5 });
		ObjectManager::Instantiate<UIText>({ 15,0 })->SetText(L"UI �ؽ�Ʈ �̷��� �����", { 0.4,0.4 });

		ObjectManager::Instantiate<Block>({ 0,200 });
		ObjectManager::Instantiate<Block>({ 100,200 });
		ObjectManager::Instantiate<Block>({ 200,200 });
		ObjectManager::Instantiate<Block>({ 300,100 });
		ObjectManager::Instantiate<Block>({ 400,200 });
		ObjectManager::Instantiate<Block>({ -100,100 });
		ObjectManager::Instantiate<Block>({ 0,-100 });;

		ObjectManager::Instantiate<Tank>()->position = { -500,-100 };

		ObjectManager::Instantiate<Player>();

		ObjectManager::Instantiate<ASD>()->position = { 200,-100 };
		break;
	case SceneManager::Scene::InGame:
		ObjectManager::Instantiate<Text>({ 0, -100 })->SetText(L"����� ���Ӿ�", { 0.5,0.5 });
		ObjectManager::Instantiate<ASD>();
		break;
	default:
		break;
	}
}
